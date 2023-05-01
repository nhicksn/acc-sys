// header file which stores function stubs
#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <unordered_map>

using userIter = unordered_map<string, string>::iterator;

class database {
private:

    std::unordered_map<std::string, std::string> users; // maps usernames to passwords

public:

    userIter registerUser(std::string& username, std::string& password);

    userIter findUser(std::string& username);

    bool checkPassword(userIter& user, std::string& pass);
};

#endif SYSTEM_H