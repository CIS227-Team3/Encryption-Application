 /*
 * fileOperations.cpp
 *
 *  Created on: Feb 11, 2023
 *      Author: Group 3
 */

#include "fileOperations.h"

void encryptPasswords() {
	unsigned short int numSuccessful = 0;
	unsigned short int numFailure = 0;
	unsigned short int numSkipped = 0;

	string tmpFilename;
	string selectQuery = "SELECT * FROM users"; // table data is stored in users table in testUsers.db
	string rowCountQuery = "SELECT COUNT(*) FROM users as rowCount";
	string updateQuery = "UPDATE users SET password = ?, hash = ? WHERE username = ?";
	int numRows = 0;

	string username;
	string password;
	int isHashed;

	MD5 md5; // creates an instance of a hashing object
	deque<User> userDeq;

	// gets filename from user
	cout << "Please enter a file name: " << endl;
	cin >> tmpFilename;

	// converts string to cstring so filename can be used as parameter in sqlite_open function
	// reference: https://www.geeksforgeeks.org/convert-string-char-array-cpp/
	const char* filename = tmpFilename.c_str();

	// reads user database information
	sqlite3 *userDB;
	try {
		// gets the number of rows in the database
		if (sqlite3_open(filename, &userDB) == SQLITE_OK) {
			cout << "Database opened successfully" << endl;

			sqlite3_stmt *rowCount;
			sqlite3_prepare_v2(userDB, rowCountQuery.c_str(), rowCountQuery.length(), &rowCount, nullptr);

			if (sqlite3_step(rowCount) != SQLITE_DONE) {
				numRows = sqlite3_column_int(rowCount, 0);
				cout << "Number of rows: " << numRows << endl;
			}

			// statement destructor
			sqlite3_finalize(rowCount);
		}

		// gets user information from the database
		sqlite3_stmt *query;
		sqlite3_prepare_v2(userDB, selectQuery.c_str(), selectQuery.length(), &query, nullptr);

		for (int i = 0; i < numRows; ++i) {
			sqlite3_step(query);
			username = (const char*)sqlite3_column_text(query, 0); // column 0 contains username
			password = (const char*)sqlite3_column_text(query, 1); // column 1 contains password
			isHashed = sqlite3_column_int(query, 2); // column 2 contains hash status

			User user(username, password, isHashed);
			userDeq.push_back(user);
		}

		// statement destructor
		sqlite3_finalize(query);

	}

	catch(...) {
		cout << "Error opening or accessing database." << endl;
	}

	// closes database connection
	sqlite3_close(userDB);

	// updates user database
	sqlite3 *updateDB;
	try {
		sqlite3_open(filename, &updateDB);
		sqlite3_stmt *update = NULL;
		sqlite3_prepare_v2(updateDB, updateQuery.c_str(), updateQuery.length(), &update, nullptr);

		for (unsigned short int i = 0; i < userDeq.size(); ++i) {
			// hashes password and updates encrypt status if encrypt status is false
			if (userDeq.at(i).getEncryptStatus() == 0) {

				username = userDeq.at(i).getUsername();
				password = userDeq.at(i).getPassword();
				md5(password); // initializes md5 constructor
				password = md5.getHash(); // gets the hashed value for the password

				isHashed = 1; // updates hash status to 1 for true

				sqlite3_bind_text(update, 1, password.c_str(), password.length(), NULL);
				sqlite3_bind_int(update, 2, isHashed);
				sqlite3_bind_text(update, 3, username.c_str(), username.length(), NULL);

				sqlite3_step(update);
				sqlite3_reset(update);
				numSuccessful++;

			}

			else {
				cout << "Username skipped: " << userDeq.at(i).getUsername() << endl;
				numSkipped++;
			}
		}

		sqlite3_finalize(update);
	}
	catch(...) {
		cout << "Error opening and updating user database." << endl;
	}

	sqlite3_close(updateDB);


	cout << "Successfully hashed " << numSuccessful << " passwords." << endl;
	cout << "Failed to hash " << numFailure << " passwords." << endl;
	cout << "Records skipped: " << numSkipped << endl;
}


