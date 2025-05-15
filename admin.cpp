#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin() {
    users.push_back(User(1, "User1"));
    users.push_back(User(2, "User2"));
    users.push_back(User(3, "User3"));

    properties[101] = Property(101);
    properties[102] = Property(102);
    properties[103] = Property(103, "Approved");
}

Admin::~Admin() {
    // No manual deletion needed for std::vector<User>
}

void Admin::AdminMenu() {
    int option;
    cout << "\n\t\t---------- Admin Menu ----------\n";
    cout << "1. Login\n2. Access Dashboard\n3. Manage Listings\n4. Manage User Accounts\n5. Logout\n";
    cout << "Enter choice: ";
    cin >> option;

    switch (option) {
    case 1:
        cout << "Logging in... (simulated)\n";
        break;
    case 2:
        cout << "Accessing Dashboard...\n";
        break;
    case 3:
        manageList();
        break;
    case 4: {
        int uid;
        cout << "Enter user ID: ";
        cin >> uid;
        userManagement(uid);
        break;
    }
    case 5:
        cout << "Logging out...\n";
        break;
    default:
        cout << "Invalid option.\n";
    }
}

void Admin::manageList() {
    cout << "\n--- Property Listings ---\n";
    for (const auto& p : properties)
        cout << "Property ID: " << p.first << ", Status: " << p.second.status << endl;

    int pid;
    cout << "Enter Property ID to manage: ";
    cin >> pid;

    if (properties.find(pid) == properties.end()) {
        cout << "Property not found.\n";
        return;
    }

    int action;
    cout << "Choose: 1. Approve  2. Reject  3. Delete\n";
    cin >> action;

    switch (action) {
    case 1: approveProperty(pid); break;
    case 2: rejectProperty(pid); break;
    case 3: deleteProperty(pid); break;
    default: cout << "Invalid action.\n";
    }

    cout << "Choose: 1. Approve next pending  2. Discard next pending\n";
    cin >> action;
    switch (action) {
        case 1: Property::approveNextProperty(); break;
        case 2: Property::discardNextProperty(); break;
        default: cout << "Invalid action.\n";
    }
}

void Admin::userManagement(int userid) {
    User* user = findUserById(userid);
    if (!user) {
        cout << "User not found.\n";
        return;
    }

    cout << "Managing " << user->name << " (Active: " << (user->isActive ? "Yes" : "No") << ")\n";
    int action;
    cout << "1. Delete User  2. Activate User\n";
    cin >> action;

    switch (action) {
    case 1: deleteUser(userid); break;
    case 2: activeUser(userid); break;
    default: cout << "Invalid action.\n";
    }
}

void Admin::deleteUser(int userid) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->id == userid) {
            users.erase(it);
            cout << "User deleted.\n";
            return;
        }
    }
    cout << "User not found.\n";
}

void Admin::activeUser(int userid) {
    User* user = findUserById(userid);
    if (user) {
        user->isActive = true;
        cout << "User activated.\n";
    }
    else {
        cout << "User not found.\n";
    }
}

void Admin::approveProperty(int property_id) {
    properties[property_id].status = "Approved";
    cout << "Property approved.\n";
}

void Admin::rejectProperty(int property_id) {
    properties[property_id].status = "Rejected";
    cout << "Property rejected.\n";
}

void Admin::deleteProperty(int property_id) {
    if (properties.erase(property_id))
        cout << "Property deleted.\n";
    else
        cout << "Property not found.\n";
}

User* Admin::findUserById(int id) {
    for (auto& user : users) {
        if (user.id == id)
            return &user;
    }
    return nullptr;
}
