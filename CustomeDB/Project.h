#pragma once
#include<string>
using namespace std;
class Project{
private:     
	string name;   
	int id = 0;
	string description;  
	string client_id; 
	string money_earned; 
	string deadline; 
	string complete_date;
    

    

public:

	static int counter;
	void setname(string name);
	void setid(int id);
	void setdescription(string description);
	void setclient_id(string client_id);
	void setmoney_earned(string money_earned);
	void setdeadline(string deadline);
	void setcomplete_date(string complete_date);
    

	string getname();
	int getid();
	string getdescription();
	string getclient_id();
	string getmoney_earned();
	string getdeadline();
	string getcomplete_date();

};



