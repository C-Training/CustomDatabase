#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Test.h"

using namespace std;

class Model {
public:
	void enterData(string name, int price) {
		//this->id = id;
		this->databaseList.addAtEnd(databaseList.listSize() + 1, name, price);
	}

	LinkedList getData() {
		return this->databaseList;
	}

private:
	LinkedList databaseList;
};


class View {
public:
	void printStudentDetails(Model product) {
		product.getData().displayList();
	}
};

class Controller
{
public:
	Controller(Model model, View view) {
		this->model = model;
		this->view = view;
	}

	void setNameAndPrice(string name, int price) {
		model.enterData(name, price);
	}

	void getNameAndPrice() {
		model.getData();
	}

	void updateView() {
		view.printStudentDetails(model);
	}

protected:
private:
	Model model;
	View view;
};

Model retriveStudentFromDatabase() {
	Model student;
	student.enterData("Dahi bhallay", 200);
	student.enterData("pani", 200);
	student.enterData("Dahi", 300);
	student.getData().deleteAtHead();
	return student;
}


int main()
{
	Model model = retriveStudentFromDatabase();
	View view;

	Controller controller(model, view);

	controller.updateView();

	//controller.setStudentName("habshi");

	//controller.updateView();
}


