#include "Property.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// Define static members
std::vector<Property> Property::savedProperties;
std::queue<Property> Property::rejectedProperties;

Property::Property(int area, float price, string location, string title, string propertyid, string propertyType) {
    this->area = area;
    this->propertyId = propertyid;
    this->price = price;
    this->location = location;
    this->title = title;
    this->propertyType = propertyType;
}
Property::Property() {}
Property::~Property() {}

void Property::setPropertyId(string ID) { propertyId = ID; }
void Property::setPropertyArea(int Area) { area = Area; }
void Property::setPropertyLocation(string Location) { location = Location; }
void Property::setPropertyTitle(string Title) { title = Title; }
void Property::setPrice(int Price) { price = Price; }
int Property::getArea() { return area; }
float Property::getPrice() { return price; }
string Property::getLocation() { return location; }
string Property::getTitle() { return title; }

void Property::addPost() {
    Property newProperty;
    cout << "Enter the property Id: ";
    cin >> newProperty.propertyId;
    cout << "Enter the title of the ad: ";
    cin >> newProperty.title;
    cout << "Enter the location of the property: ";
    cin >> newProperty.location;
    cout << "Enter the price of the property: ";
    cin >> newProperty.price;
    cout << "Enter the area of the property: ";
    cin >> newProperty.area;
    cout << "Enter the property type: ";
    cin >> newProperty.propertyType;
    rejectedProperties.push(newProperty); // Add to rejected queue by default
    cout << "Property added to pending (rejected) queue for admin approval.\n";
}

void Property::editPost() {
    string editId;
    cout << "Enter property id to edit: ";
    cin >> editId;
    for (auto& prop : savedProperties) {
        if (prop.propertyId == editId) {
            int option;
            cout << "1. Change title\n2. Change price\n3. Change area\n4. Change location\n";
            cin >> option;
            switch (option) {
                case 1:
                    cout << "Enter new title: ";
                    cin >> prop.title;
                    break;
                case 2:
                    cout << "Enter new price: ";
                    cin >> prop.price;
                    break;
                case 3:
                    cout << "Enter new area: ";
                    cin >> prop.area;
                    break;
                case 4:
                    cout << "Enter new location: ";
                    cin >> prop.location;
                    break;
                default:
                    cout << "Invalid option.\n";
            }
            cout << "Property updated.\n";
            return;
        }
    }
    cout << "Property not found.\n";
}

void Property::deletePost() {
    string delId;
    cout << "Enter property id to delete: ";
    cin >> delId;
    auto it = std::remove_if(savedProperties.begin(), savedProperties.end(),
        [&delId](const Property& prop) { return prop.propertyId == delId; });
    if (it != savedProperties.end()) {
        savedProperties.erase(it, savedProperties.end());
        cout << "Property deleted.\n";
    } else {
        cout << "Property not found.\n";
    }
}

void Property::viewMyPosts() {
    int count = 1;
    for (const auto& prop : savedProperties) {
        cout << count++ << ". Property Data:\n";
        cout << "\tID: " << prop.propertyId << "\n";
        cout << "\tTitle: " << prop.title << "\n";
        cout << "\tLocation: " << prop.location << "\n";
        cout << "\tPrice: " << prop.price << "\n";
        cout << "\tArea: " << prop.area << "\n";
        cout << "\tType: " << prop.propertyType << "\n";
    }
}

void Property::rejectProperty(const Property& prop) {
    rejectedProperties.push(prop);
    cout << "Property rejected and added to the rejected queue.\n";
}

void Property::approveNextProperty() {
    if (!rejectedProperties.empty()) {
        Property prop = rejectedProperties.front();
        rejectedProperties.pop();
        savedProperties.push_back(prop);
        std::cout << "Property approved and moved to saved properties.\n";
    } else {
        std::cout << "No properties pending approval.\n";
    }
}

void Property::discardNextProperty() {
    if (!rejectedProperties.empty()) {
        rejectedProperties.pop();
        std::cout << "Property discarded from pending queue.\n";
    } else {
        std::cout << "No properties pending approval.\n";
    }
}

void Property::savePropertiesToFile(const std::string& filename) {
    std::ofstream out(filename, std::ios::out | std::ios::trunc); // Create or overwrite
    if (!out) {
        std::cerr << "Error: Could not open file for saving properties.\n";
        return;
    }
    for (const auto& prop : savedProperties) {
        out << prop.propertyId << "," << prop.title << "," << prop.location << ","
            << prop.price << "," << prop.area << "," << prop.propertyType << "\n";
    }
    out.close();
}

void Property::loadPropertiesFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        // File does not exist, create an empty file
        std::ofstream out(filename);
        out.close();
        return;
    }
    savedProperties.clear();
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        Property prop;
        std::getline(iss, prop.propertyId, ',');
        std::getline(iss, prop.title, ',');
        std::getline(iss, prop.location, ',');
        std::string priceStr, areaStr;
        std::getline(iss, priceStr, ',');
        std::getline(iss, areaStr, ',');
        std::getline(iss, prop.propertyType, '\n');
        prop.price = std::stof(priceStr);
        prop.area = std::stoi(areaStr);
        savedProperties.push_back(prop);
    }
    in.close();
}

