#pragma once
#include <iostream>
#include<string>



class Admin
{
public:
	Admin();
	~Admin();
	void AdminMenu();
	void deleteUser(int userid);
	void activeUser(int userid);
	void approveProperty(int property_id);
	void rejectProperty(int property_id);
	void deleteProperty();
	//void listProperty();
	void userManagement(int userid) {}


};
};


