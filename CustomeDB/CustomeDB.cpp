#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Test.h"

using namespace std;

class Model {
public:
	void setPrice(int price) {
		this->price = price;
	}
	void setName(string name){
		this->name = name;
	}
	void setId(int id) { this->id = id; }

	int getid() {
		return this->id;
	}
	string getName() {
		return name;
	}
	int getPrice() {
		return price;
	}

private:
	int id;
	string name;
	int price;
};


class View {
public:
	void printStudentDetails(LinkedList database) {
		/*product.getData().displayList();*/
		database.displayList();
		
	}
};

class Controller
{
	LinkedList database;
public:
	Controller(Model model, View view) {
		this->model = model;
		this->view = view;
	}

	void setNameAndPrice(string name, int price) {
		model.setId(this->database.listSize() + 1);
		model.setName(name);
		model.setPrice(price);
		this->database.addAtEnd(model.getid(), model.getName(), model.getPrice());
	}

	/*Node *getNameAndPrice() {
		return database.getHead();
	}*/

	void deleteItem() {
		this->database.deleteAtHead();
	}

	void updateItem() {
		this->database.updatePrice(200, 500);
	}

	void updateView() {
		view.printStudentDetails(database);
	}

protected:
private:
	Model model;
	View view;
};


int main()
{
	Model *model = new Model;
	//model = model->retriveProductFromDatabase();
	View *view = new View;


	Controller *controller = new Controller(*model, *view);
	controller->setNameAndPrice("abad", 500);
	controller->setNameAndPrice("dahi", 200);
	controller->setNameAndPrice("bhallay", 200);
	controller->setNameAndPrice("gg", 700);
	controller->deleteItem();
	controller->updateItem();
	controller->updateView();

	//Test();

	//controller.setStudentName("habshi");

	//controller.updateView();
}


