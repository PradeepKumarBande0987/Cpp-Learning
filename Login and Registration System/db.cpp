#include <iostream>
#include "db.h"
using namespace std;

Database::Database() {
    db = nullptr;
}

bool Database::connect(const char* filename) {
    int result = sqlite3_open(filename, &db);

    if(result) {
        cout << "Cannot open database" << endl;
        return false;
    }

    cout << "Database connected successfully" << endl;
    return true;
}

bool Database::createUsersTable() {
    const char* sql = 
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT NOT NULL,"
        "password TEXT NOT NULL;";

    char* errorMesssage = nullptr;

    int result = sqlite3_exec(
        db,
        sql,
        nullptr,
        nullptr,
        &errorMesssage
    );

    if (result != SQLITE_OK) {
        cout << errorMesssage << endl;
        sqlite3_free(errorMesssage);
        return false;
    }

    return true;
}

bool Database::addUser(string username, string password) {
        string sql =
        "INSERT INTO users(username,password) VALUES('"
        + username + "','"
        + password + "');";

    char* errorMessage = nullptr;

    int result = sqlite3_exec(
        db,
        sql.c_str(),
        nullptr,
        nullptr,
        &errorMessage
    );

    if (result != SQLITE_OK) {
        cout << errorMessage << endl;
        sqlite3_free(errorMessage);
        return false;
    }

    return true;
}

void Database::disconnect() {
    if(db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
        cout << "Database closed" << endl;
    }
}