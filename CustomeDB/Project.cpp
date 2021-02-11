#include "Project.h"

void Project::setname(string name)
{
	this->name = name;
}

int Project::counter = 1;

void Project::setid(int id)
{
	this->id = counter++;
}

void Project::setdescription(string description)
{
	this->description = description;
}

void Project::setclient_id(string client_id)
{
	this->client_id = client_id;
}

void Project::setmoney_earned(string money_earned)
{
	this->money_earned = money_earned;
}

void Project::setdeadline(string deadline)
{
	this->deadline = deadline;
}

void Project::setcomplete_date(string complete_date)
{
	this->complete_date = complete_date;

}

string Project::getname()
{
	return name;
}

int Project::getid()
{
	return id;
}

string Project::getdescription()
{
	return description;
}

string Project::getclient_id()
{
	return client_id;
}

string Project::getmoney_earned()
{
	return money_earned;
}

string Project::getdeadline()
{
	return deadline;
}

string Project::getcomplete_date()
{	
	return complete_date;
}



