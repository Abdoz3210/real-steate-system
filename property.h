#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>

class Property {
private:
    std::string location;
    std::string propertyType;
    std::string title;
    std::string propertyId;
    float price;
    int area;
public:
    int id;
    std::string status;

    Property();
    Property(int area, float price, std::string location, std::string title, std::string propertyid, std::string propertyType);
    Property(int id, const std::string& status = "Pending")
        : id(id), status(status) {}
    ~Property();

    void setPrice(int newPrice);
    void setPropertyArea(int area);
    void setPropertyId(std::string ID);
    void setPropertyTitle(std::string title);
    void setPropertyLocation(std::string location);
    int getArea();
    float getPrice();
    std::string getLocation();
    std::string getTitle();

    // Static containers for all properties
    static std::vector<Property> savedProperties;
    static std::queue<Property> rejectedProperties;

    static void addPost(); // Declare static method
    static void editPost();
    static void deletePost();
    static void viewMyPosts();
    static void rejectProperty(const Property& prop);
    static void approveNextProperty();
    static void discardNextProperty();

	static void savePropertiesToFile(const std::string& filename);
    static void loadPropertiesFromFile(const std::string& filename);
	
};

