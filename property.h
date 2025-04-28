#pragma once
#include <iostream>
#include<string>
#include<fstream>
class Property{

int area;
float price;
string location;
string title;
int propertyid;
public:
	Property();
	Property(int area, float price, string location, string title, int propertyid);
	~Property();
	void deleteAdd(int property_id);
	void editAdd(int newarea, float newprice, string newlocation, string newtitle, int choice, int property_id);
	void postAdd(int area, float price, string title, string location, int property_id);
	void view_my_adds();


};

