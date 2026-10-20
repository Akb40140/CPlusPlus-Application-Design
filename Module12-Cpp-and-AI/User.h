// User.h - the User class and the two roles
#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string username;
    string role;

public:
    User(string name, string userRole) {
        username = name;
        role = userRole;
    }

    string getName() {
        return username;
    }

    string getRole() {
        return role;
    }

    // Only an Admin can add, update, or delete
    bool canEdit() {
        return role == "Admin";
    }
};

class Admin : public User {
public:
    Admin(string name) : User(name, "Admin") {}
};

class RegularUser : public User {
public:
    RegularUser(string name) : User(name, "Regular User") {}
};

#endif
