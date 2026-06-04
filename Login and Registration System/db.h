#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
using namespace std;

class Database {
    private:
        sqlite3* db;
    public:
        Database();

        bool connect(const char* filename);

        void disconnect();

        bool createUsersTable();

        bool addUser(string username, string password);
};

#endif