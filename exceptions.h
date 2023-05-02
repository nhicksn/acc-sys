// custom exception definitions

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

class systemException : public std::exception {
private:
    std::string filename;

public:
    systemException(const std::string& filenameIn) : filename(filenameIn) { }

    std::string fileError() {
        return ("Error opening file " + filename); 
    }
};  




#endif