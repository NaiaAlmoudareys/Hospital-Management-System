#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& username, const std::string& password, const std::string& role);

    bool registerUser();
    bool loginUser();
    void viewProfile();
    void updateProfile();

private:
    std::string username;
    std::string password;
    std::string role;
    std::string encryptPassword(const std::string& pwd);
};

#endif
