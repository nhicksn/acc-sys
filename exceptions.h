// custom exception definitions

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

class systemException : public std::exception {
private:
    std::string filename;

public:
    systemException(const std::string& filenameIn) : filename(filenameIn) { }

    virtual const char* what() const throw() {
        return "database file could not be opened\n";
    }
};  

#endif