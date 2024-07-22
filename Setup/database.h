#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

class Database {
public:
    Database(const std::string& dbName);
    ~Database();
    
    bool executeQuery(const std::string& query);
    sqlite3* getDB() const;

private:
    sqlite3* db;
};

#endif
