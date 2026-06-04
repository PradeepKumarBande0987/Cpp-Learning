#include <iostream>
#include <ctime>
#include <string>
#include "db.h"

using namespace std;

int main () {
    Database db;

    if(db.connect("Database.db")) {
        cout << "Welcome to the C++ Learning!" << endl;
    }

    db.disconnect();
    return 0;
}