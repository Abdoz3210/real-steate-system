#ifndef ADMIN_H
#define ADMIN_H

#include <vector>
#include <unordered_map>
#include "User.h"
#include "Property.h"

class Admin {
private:
    std::vector<User> users;
    std::unordered_map<int, Property> properties;

public:
    Admin();
    ~Admin();

    void AdminMenu();
    void manageList();
    void userManagement(int userid);
    void deleteUser(int userid);
    void activeUser(int userid);
    void approveProperty(int property_id);
    void rejectProperty(int property_id);
    void deleteProperty(int property_id);

    // Helpers
    User* findUserById(int id);
};

#endif

//i need from user.h 

//struct User {
//    int id;
//    string name;
//    bool isActive;
//
//    User(int i, const std::string& n, bool active = true)
//        : id(i), name(n), isActive(active) {
//    }
//};

// and from property.h
//struct Property {
//    int id;
//    string status; // e.g., "Pending", "Approved", "Rejected"
//
//    Property(int i, const std::string& s = "Pending")
//        : id(i), status(s) {
//    }
//};

