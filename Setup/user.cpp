#include "user.h"
#include "database.h"
#include "encryption.h"
#include <iostream>

extern Database db;

User::User(const std::string& username, const std::string& password, const std::string& role)
    : username(username), password(password), role(role) {}

bool User::registerUser() {
    std::string encryptedPassword = encryptPassword(password);
    std::string query = "INSERT INTO users (username, password, role) VALUES ('" + username + "', '" + encryptedPassword + "', '" + role + "')";
    return db.executeQuery(query);
}

bool User::loginUser() {
    std::string encryptedPassword = encryptPassword(password);
    std::string query = "SELECT * FROM users WHERE username = '" + username + "' AND password = '" + encryptedPassword + "'";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db.getDB(), query.c_str(), -1, &stmt, nullptr);
    bool result = (sqlite3_step(stmt) == SQLITE_ROW);
    sqlite3_finalize(stmt);
    return result;
}

void User::viewProfile() {
    // Implementation to view user profile
}

void User::updateProfile() {
    // Implementation to update user profile
}

std::string User::encryptPassword(const std::string& pwd) {
    return Encryption::encrypt(pwd);
}
