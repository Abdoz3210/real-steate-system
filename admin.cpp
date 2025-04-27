#include "Admin.h"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
class Admin {
	// misssing the constructors
	

public:
	void  manageList() {
	
	}
//	void  usermanagement(int userid) {}
	void deleteUser(int userid) {}
	void activeUser(int userid ) {}
	void approveProperty(int property_id) {}
	void rejectproperty(int property_id ) {}
	void delete_property() {}
	void list_property() {}
	//missing is empty because we cant delete property if there is no property

};