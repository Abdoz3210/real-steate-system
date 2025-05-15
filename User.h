#pragma once
#include <iostream>
#include <string>
#include "Buyer.h"
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <memory>

class User
{
public:
    int id;
    std::string name;
    bool isActive;

    User(int id, const std::string& name)
        : id(id), name(name), isActive(true) {}

    void listProperties();
    void propertyComparison(Buyer b1, Buyer b2, Buyer b3, Buyer b4);
    void searchBylocation(std::string location);
    void searchByproperty_type(std::string property_type);
    void searchBypricerange(int MinNum, int MaxNum);
    void searchBytitle(std::string title);
    void fillter(int MinNum, int MaxNum, std::string location, std::string property_type);
    static void saveUsersToFile(const std::string& filename);
    static void loadUsersFromFile(const std::string& filename);

};

