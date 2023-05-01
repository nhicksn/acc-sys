// implementation file for the system
#include "system.h"
#include <string>
#include <unordered_map>

using namespace std;

using userIter = unordered_map<string, string>::iterator;

class database {
private:

    unordered_map<string, string> users; // maps usernames to passwords

public:

    // returns an iterator to the new user
    userIter registerUser(string& username, string& password) {

    }

    // returns true if the username was found in the database, false otherwise
    userIter findUser(string& username) {
        return users.find(username);
    }

    bool checkPassword(userIter& user, string& pass) {
        if(user == users.end()) return false;

        if(user->second == pass) return true;

        return false;
    }

};