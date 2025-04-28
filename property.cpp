#include "Property.h"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;



Property::Property(int area,float price,string location , string title , int propertyid){
	this->area = area;
	this->propertyid = propertyid;
	this->price = price;
	this->location = location;
	this->title = title;
	
	
}
Property::Property()
{
}

Property::~Property()
{
}

void Property::postAdd(int area , float price , string title , string location,int property_id  ) {
	
		cout << "enter the oroperty id  :";
		cin >> property_id;

		cout << "enter the  title of the add  :";
		cin >> title;

		cout << "enter the location of the property :";
		cin >> location;

		cout << "enter the price of the property :";
		cin >> price;

		cout<<"enter the area of the property :";
		cin >> area;
		//must make this information saved into an exel file 
	}


void Property::editAdd(int newarea, float newprice , string newlocation , string newtitle, int choice, int property_id   ) {
	cout << "enter property id :";
	cin >> property_id;
	if (property_id == propertyid)
	{
		//must take the properties id from the exel file to compare the property id

		while (true)
		{
			cout << " to change the title  choose 1      " << endl << "to change price  choose 2 " << endl << "to change  area choose 3 " << endl << "to change location choose 4" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "enter the new title :";
				cin >> newtitle;
				cout << "the title updated the new title is :" << newtitle;
				break;
			}
			else if (choice == 2)
			{
				cout << "enter the new price :";
				cin >> newprice;
				cout << "price updated the new price is :" << newprice;
				break;
			}
			else if (choice == 3) {
				cout << "enter the new area :";
				cin >> newarea;
				cout << "area updated the new area is :" << newarea;
				break;
			}
			else if (choice == 4)
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
//must update the information in the file too!!!!
}
void Property::deleteAdd(int property_id) {
	cout << "enter the property id that you want to deleted ";
	cin >> property_id;

}
void Property::view_my_adds() {}
	//we can use a que in here to deleat an add in any place of the array
	//we must put the add in a array of objects 
	//each objct contains id,type,location,price,area

