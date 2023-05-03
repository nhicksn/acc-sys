// Account System with a username and password
// Includes registration process
// Stores accounts in a database txt

#include "system.h"
#include "exceptions.h"
#include <iostream>

using namespace std;

int main() {
    database data("database.txt");

    string command;
    string username;
    string password;

    cout << "input command, or 'help' for use instructions\n";

    cin >> command;

    while(command != "quit") {
        if(command == "register") {
            cout << "input username: ";
            cin >> username; cout << "input password: ";
            cin >> password;
            try {
                if(data.registerUser(username, password)) {
                    cout << "User " << username << " successfully created\n";
                }
                else {
                    cout << "User " << username << " could not be created; " 
                    << "username is already in the database\n";
                }
            }
            catch (exception& e){
                cout << e.what();
            }
        }
        else if(command == "delete") {
            cout << "input username: ";
            cin >> username; cout << "input password: ";
            cin >> password;
            try {
                if(data.deleteUser(username, password)) {
                    cout << "User " << username << " successfully deleted\n";
                }
                else {
                    cout << "User " << username << " could not be deleted; " 
                    << "either it does not exist or password was incorrect\n";
                }
            }
            catch (exception& e){
                cout << e.what();
            }
        }
        else if(command == "change") {
            cout << "input username: ";
            cin >> username;
            try {
                if(data.changePassword(username)) {
                    cout << username << "'s password was successfully changed\n";
                }
                else {
                    cout << "Action could not be completed: user " 
                        << username << " is not in the database\n";
                }
            }
            catch(exception &e) {
                cout << e.what();
            }
        }
        else if(command == "help") {
            help();
        }
        else {
            cout << "\ninvalid command '" << command << "'; say 'help' for use instructions\n";
        }

        cout << "\nInput next command: "; cin >> command;
    }

    return 0;
}