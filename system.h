// header file which stores function stubs
#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class database {
private:

    std::string filename;

    // returns true if the username was found in the database, false otherwise
    bool findUser(const std::string& username);

public:

    database(const std::string& filenameIn);

    // returns true if a new user was created, false if username already exists
    bool registerUser(const std::string& username, const std::string& password);

    // returns true if a user was deleted, false if user does not exist or password is wrong
    bool deleteUser(const std::string& username, const std::string& password);
};

#endif