/*
 * User.h
 *
 *  Created on: Jan 25, 2023
 *      Author: Group 3
 */

#ifndef USER_H_
#define USER_H_

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
// #include "Book.h"

using namespace std;

//CLass User
class User {
public:
    User();

    User(string username, string password, int encrypt);

    void setUsername(string username);
    string getUsername() const;

    void setPassword(string password);
    string getPassword() const;

    void setEncryptStatus(int encrypted);
    int getEncryptStatus();

    void updatePassword(string username, string password);

    void listUserList();

private:
    string username;
    string password;
    int encrypted;

    // deque<Book> UserList;
};

#endif /* USER_H_ */
