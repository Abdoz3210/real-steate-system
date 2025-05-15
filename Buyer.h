#pragma once
#include <string>

class Buyer {
public:
    double area;
    double price;
    std::string location;
    std::string property_type;

    Buyer() : area(0.0), price(0.0), location(""), property_type("") {}
    Buyer(double area, double price, const std::string& location, const std::string& property_type)
        : area(area), price(price), location(location), property_type(property_type) {}
};