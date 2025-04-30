#include "Property.h"
#include <iostream>
#include <string>

using namespace std;



Property::Property(int area,float price,string location , string title , string propertyid,string propertyType){
	this->area = area;
	this->propertyId = propertyid;
	this->price = price;
	this->location = location;
	this->title = title;
	this->propertType = propertyType;
	
}
Property::Property(){}

Property::~Property(){}

Property::setPropertyId(string ID) {
	propertyId = ID;
}
Property::setPropertyArea(int Area) {
	area = Area;
}
Property::setPropertyLocation(string Location) {
	location = Location;
}
Property::setPropertyTitle(string Title) {
	title = Title;
}
Property::setPrice(int Price) {
	price = Price;
}
Property::getArea() {
	return area;
}
Property::getPrice() {
	return price;
}
Property::getLocation() {
	return location;
}
Property::getTitle() {
	return title;
}

void Property::addPost(/*pass DS that containt Propertys*/) {
	Property newProperty;
	cout << "enter the oroperty Id: ";
	cin >> newProperty.propertyId
	cout << "enter the  title of the add: ";
	cin >> newProperty.title;
	cout << "enter the location of the property: ";
	cin >> newProperty.location;
	cout << "enter the price of the property: ";
	cin >> newProperty.price;
	cout<<"enter the area of the property: ";
	cin >> newProperty.area;
	cout << "enter the property type: ";
	cin >> newProperty.propertyType;
	//must make this information saved by add it into DS that containt Propertys 
	}


void Property::editPost(int optionsVariable, string intagerOptionsVariable /*pass DS that containt Propertys*/) {
	cout << "enter property id: ";
	cin >> intagerOptionsVariable;

	for(auto Propertyx:/*DS that containt Propertys*/){
		if (property_id == propertyId){
			//must take the properties id from the exel file to compare the property id

			while (true)
			{
				cout << "to change the title  choose 1 "<< "\nto change price  choose 2\nto change  area choose 3\nto change location choose 4\n";
				cin >> optionsVariable;
				if (optionsVariable == 1)
				{
					cout << "enter the new title :";
					cin >> newtitle;
					cout << "the title updated the new title is :" << newtitle;
					break;
				}
				else if (optionsVariable == 2)
				{
					cout << "enter the new price :";
					cin >> newprice;
					cout << "price updated the new price is :" << newprice;
					break;
				}
				else if (optionsVariable == 3) {
					cout << "enter the new area :";
					cin >> newarea;
					cout << "area updated the new area is :" << newarea;
					break;
				}
				else if (optionsVariable == 4)
				{
					cout << "enter the new location :";
					cin >> newlocation;
					cout << "location updated  the new location is :" << newlocation;
					break;
				}
				else
				{
					cout << "wrong choice choose a number between 1 to 4 :";

				}
			}
		}
	}
//must update the information in the file too!!!!
}
void Property::deletePost(string property_id) {
	cout << "enter the property id that you want to deleted ";
	cin >> property_id;

}
void Property::viewMyPosts(/*pass DS that containt Propertys*/) {
		int count = 1;
	for (Property PropertyX :/*DS that containt Propertys*/) {
		cout<<count<<". Property Data:- \n\t"
		cout << PropertyX.getTitle()<<"\n\t"<<PropertyX.;
	}
}



	//we can use a que in here to deleat an add in any place of the array
	//we must put the add in a array of objects 
	//each objct contains id,type,location,price,area

