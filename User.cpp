/*
 * User.cpp
 *
 *  Created on: Jan 25, 2023
 *      Author: Group 3
 */

#include <deque>
#include "User.h"

//Constructor
User::User() {
    username = "none";
    password = "none";
    encrypted = 0;
}

//Makes a User
User::User(string username, string password, int encrypt) {
    this->username = username;
    this->password = password;
    // this->UserList;
    this->encrypted = encrypt;
}

//Sets Username
void User::setUsername(string username) {
    this->username = username;
}

//Gets Username
string User::getUsername() const {
    return username;
}

//Sets Password
void User::setPassword(string password) {
    this->password = password;
}

//Gets Password
string User::getPassword() const {
    return password;
}

void User::setEncryptStatus(int encrypted) {
	this->encrypted = encrypted;
}

int User::getEncryptStatus() {
	return encrypted;
}

//Updates Password
void User::updatePassword(string username, string password) {

}

//Lists user's list in terminal
/*
void User::listUserList() {
    cout << "ISBN | Book-Title | Book-Author" << endl;
    for (auto &book: this->UserList) {
        cout << book.ISBN << " | " << book.title << " | " << book.author << endl;
    }

    cout << "Total items in list: " << this->UserList.size();
}
*/
