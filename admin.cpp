#include "Admin.h"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;


Admin::Admin()
{
}

Admin::~Admin()
{
}
void Admin::AdminMenu(int optionsVariable) {
	cout << "\t\t---------- Admin Menu ----------\n\nThe Menu:-\n\t1. Login\n\t2. Access Dashboard\n\t3. Manage Listings\n\t4. Manage User Accounts\n\t5. Logout\n";
	cout << "Please enter the number of your choice: ";
	cin >> optionsVariable;
	switch (optionsVariable){
	case 1: {
		break;
	}
	case 2: {
		break;
	}
	case 3: {
		manageList();
		break;
	}
	case 4: {
		break;
	}
	case 5: {
		break;
	}
	
	default:
		break;
	}
}
void Admin::manageList() {}
void Admin::userManagement(int userid) {}
void Admin::deleteUser(int userid) {}
void Admin::activeUser(int userid ) {}
void Admin::approveProperty(int property_id) {}
void Admin::rejectProperty(int property_id ) {}
void Admin::deleteProperty() {}
//void Admin::listProperty() {}
//missing is empty because we cant delete property if there is no property

