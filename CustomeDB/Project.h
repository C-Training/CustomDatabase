#pragma once
#include<string>
using namespace std;
class Project{
private:     
	string name;   
	int id;
	string description;  
	int client_id; 
	int money_earned; 
	string deadline; 
	string complete_date;

public:

	void setname(string name);
	void setid(int id);
	void setdescription(string description);
	void setclient_id(int client_id);
	void setmoney_earned(int money_earned);
	void setdeadline(string deadline);
	void setcomplete_date(string complete_date);

	string getname();
	int getid();
	string getdescription();
	int getclient_id();
	int getmoney_earned();
	string getdeadline();
	string getcomplete_date();


};

