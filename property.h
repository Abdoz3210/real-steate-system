#pragma once
#include <iostream>
#include<string>

class Property{
private:
	string location;
	string propertyType;
	string title;
	string propertyId;
	//float price;
	int area;
public:
	Property();
	//Property(int area, float price, string location, string title, string propertyid);
	~Property();

	void setPrice(int newPrice);
	void setPropertyArea(int area);
	void setPropertyId(string ID);
	void setPropertyTitle(string title);
	void setPropertyLocation(string location);
	int getArea();
	int getPrice();
	string getLocation();
	string getTitle();

	void addPost(/*pass DS that containt Propertys*/);
	void editPost(int optionsVariable, string stringOptionsVariable /*pass DS that containt Propertys*/);
	void deletePost(string propertyId /*pass DS that containt Propertys*/);
	void viewMyPosts(/*pass DS that containt Propertys*/);

		
};

