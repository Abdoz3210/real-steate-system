#include <iostream>
#include <vector>
#include <algorithm>
#include "Admin.h"
#include "User.h"
#include "Property.h"
#include "Buyer.h"

using namespace std;

// void propertyComparison(Buyer b1, Buyer b2, Buyer b3, Buyer b4);

int main() {
    std::vector<User> users;
    int nextUserId = 1;

    Property::loadPropertiesFromFile("properties.txt");

    while (true) {
        std::cout << "1. Register\n2. Login\n3. Admin Login\n4. Exit\n";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::string name;
            std::cout << "Enter your name: ";
            std::cin >> name;
            users.emplace_back(nextUserId++, name);
            std::cout << "Registered! Your user ID is " << nextUserId-1 << "\n";
        } else if (choice == 2) {
            int id;
            std::cout << "Enter your user ID: ";
            std::cin >> id;
            auto it = std::find_if(users.begin(), users.end(), [id](const User& u){ return u.id == id; });
            if (it != users.end()) {
                std::cout << "Welcome, " << it->name << "!\n";
                // User menu here
                bool userMenu = true;
                while (userMenu) {
                    std::cout << "1. Add Property\n2. Compare Properties\n3. Logout\n";
                    int userChoice;
                    std::cin >> userChoice;
                    if (userChoice == 1) {
                        Property::addPost();
                    } else if (userChoice == 2) {
                        // Add code to compare properties
                    } else {
                        userMenu = false;
                    }
                }
            } else {
                std::cout << "User not found.\n";
            }
        } else if (choice == 3) {
            // Admin login (you can add password check here)
            Admin admin;
            admin.AdminMenu();
        } else {
            break;
        }
    }

    Property::savePropertiesToFile("properties.txt");
    std::cout << "\nTest complete.\n";
    return 0;
}