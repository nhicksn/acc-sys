// implementation file for the system

#include "system.h"
#include "exceptions.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// outputs message on how to use
void help() {
    cout << "\nThere are 5 command options:\n"
    << "'register' creates a new account, and stores it in the database\n"
    << "'delete' removes an existing account from the database\n"
    << "'change' edits the password of an existing user\n"
    << "'help' prints this message\n"
    << "and 'quit' exits the program\n";
}

// returns true if the username was found in the database, false otherwise
bool database::findUser(const string& username) {
    
    // open file
    ifstream file(filename);
    if(!file.is_open()) throw systemException(filename);

    string user;

    while(file >> user) {
        if(user == username) return true;

        file >> user; // get rid of password
    }

    return false;
}

database::database(const string& filenameIn) : filename(filenameIn) { }

// returns true if a new user was created, false if username already exists
bool database::registerUser(const string& username, const string& password) {

    // if username is already in database
    if(findUser(username)) return false;

    // open database file
    ofstream file(filename, ios::app);
    if(!file.is_open()) {
        cout << "Error opening file: " << filename << "\n";
        throw systemException(filename);
    }

    // add user to database
    file << username << ' ' << password << '\n';

    file.close();

    return true;
}

// returns true if a user was deleted, false if user does not exist or password is wrong
bool database::deleteUser(const string& username, const string& password) {

    if(!findUser(username)) return false;

    vector<string> tempData;

    ifstream fileIn(filename);

    if(!fileIn.is_open()) throw systemException(filename);

    string user, pass;

    while(fileIn >> user >> pass) {
        if(user == username) {
            if(pass != password) return false;
            continue;
        }

        tempData.push_back(user + ' ' + pass + '\n');
    }

    ofstream fileOut(filename);

    for(size_t i = 0; i < tempData.size(); i++) {
        fileOut << tempData[i];
    }

    return true;

}

bool database::changePassword(const string& username) {
    if(!findUser(username)) return false;

    ifstream file(filename);

    if(!file.is_open()) throw systemException(filename);

    vector<string> tempData;
    string user, pass;
    string password = "initial";

    while(file >> user >> pass) {
        if(user == username) {
            while(password != pass) {
                cout << "input current password for " << username << '\n';
                cin >> password;
                if(password != pass) {
                    cout << "incorrect: ";
                }
            }
            cout << "input new password for " << username << '\n';
            cin >> password;
            tempData.push_back(username + ' ' + password + '\n');
            continue;
        }
        tempData.push_back(user + ' ' + pass + '\n');
    }

    ofstream fileOut(filename);

    for(size_t i = 0; i < tempData.size(); i++) {
        fileOut << tempData[i];
    }

    return true;
}