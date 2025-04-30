#pragma once
#include <iostream>
#include<string>

class User
{
	int MinNum;
	int MaxNum;
	string location;
	string property_type;
public:
	void listProperties();
	void propertyComparison(Buyer b1, Buyer b2, Buyer b3, Buyer b4);
	void searchBylocation(string location);
	void searchByproperty_type(string property_type);
	void searchBypricerange(int MinNum, int MaxNum);
	void searchBytitle(string title);
	void fillter(int MinNum, int MaxNum, string location, string property_type);
};

