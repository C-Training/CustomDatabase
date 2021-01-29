#include "LinkedList.h"



LinkedList::LinkedList()
{
    cout << "luvhbashi" << endl;
}

LinkedList::LinkedList(string fileName) {
    this->fileName = fileName;
    ifstream infile(fileName);
    if (infile.fail()) {
        cerr << "Error Opening File. \n";
        //exit(1);
    }
    else {
        string name;
        int id;
        double salary;
        string project;
        string joiningDate;
        string phone;
        string address;
        while (infile >> name >> id >> salary >> project >> joiningDate >> phone >> address) {
            addAtEnd(name, id, salary, project, joiningDate, phone, address);
        }
        infile.close();
    }
}
LinkedList::~LinkedList() {
    ofstream outfile;
    outfile.open(fileName, ios::out | ios::trunc);

    Node* cur = emphead;

    while (cur != NULL) {
        outfile << cur->getEmployee().getName() << " ";
        outfile << cur->getEmployee().getId() << " ";
        outfile << cur->getEmployee().getSalary() << " ";
        outfile << cur->getEmployee().getProject() << " ";
        outfile << cur->getEmployee().getJoiningDate() << " ";
        outfile << cur->getEmployee().getPhone() << " ";
        outfile << cur->getEmployee().getAddress() << endl;
        cur = cur->next;
    }
    outfile.close();
}

Node* LinkedList::getempHead()
{
    return emphead;
}

Node* LinkedList::getclientHead()
{
    return clienthead;
}

void LinkedList::addAtHead(string name, int id, double salary, string project, string joiningDate, string phone, string address)
{
	Node* new_node = new Node(name, id, salary, project, joiningDate, phone, address);
	new_node->next = NULL;

	if (emphead == NULL) {
		emphead = new_node;
	}
	else {
		Node* temp = emphead;
		emphead = new_node;
		emphead->next = temp;
	}
}

void LinkedList::addAtHead(string name, int id, string phone, string address, int project_id) {
    Node* new_node = new Node(name, id, phone, address, project_id);
    new_node->next = NULL;

    if (clienthead == NULL) {
        clienthead = new_node;
    }
    else {
        Node* temp = clienthead;
        clienthead = new_node;
        clienthead->next = temp;

    }
}

void LinkedList::addAtEnd(string name, int id, double salary, string project, string joiningDate, string phone, string address) {

    Node* new_node = new Node(name, id, salary, project, joiningDate, phone, address);
    new_node->next = NULL;

    if (emphead == NULL) {
        emphead = new_node;
    }
    else {
        Node* cur = emphead;

        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }

}

void LinkedList::addAtEnd(string name, int id, string phone, string address, int project_id) {

    Node* new_node = new Node(name, id, phone, address, project_id);
    new_node->next = NULL;

    if (clienthead == NULL) {
        clienthead = new_node;
    }
    else {
        Node* cur = clienthead;

        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }

}

void LinkedList::deleteAtHead() {

    if (emphead == NULL) {
        cout << "There is no linked list to delete" << endl;
    }
    else {
        Node* temp = emphead;
        emphead = emphead->next;

        delete temp;
    }
}

void LinkedList::deleteAtCliHead() {

    if (clienthead == NULL) {
        cout << "There is no linked list to delete" << endl;
    }
    else {
        Node* temp = clienthead;
        clienthead = clienthead->next;

        delete temp;
    }
}

void LinkedList::deleteById(int id) {

    if (emphead == NULL) {
        cout << "linked list is empty \n";
    }
    else if (emphead->getEmployee().getId() == id) {
        deleteAtHead();
    }
    else {
        Node* cur = emphead;

        bool found = false;
        while (cur != NULL) {
            if (cur->getEmployee().getId() == id ) {
                found = true;
                break;
            }
            cur = cur->next;
        }
        if (found) {

            Node* temp = emphead;

            while (temp->next != cur) {
                temp = temp->next;
            }
            temp->next = cur->next;
            delete cur;
        }
        else {
            cout << "Id doesnt exist in linked list \n";
        }
    }
}

void LinkedList::deleteById() {
    int id = 0;
    
    cout << "Enter the id whose data you want to delete" << endl;
    cin >> id;

    if (clienthead == NULL) {
        cout << "linked list is empty \n";
    }
    else if (clienthead->getClient().getId() == id) {
        deleteAtCliHead();
        cout << "Head is no more" << endl;
    }
    else {
        Node* cur = clienthead;

        bool found = false;
        while (cur != NULL) {
            if (cur->getClient().getId() == id) {
                found = true;
                break;
            }
            cur = cur->next;
        }
        if (found) {

            Node* temp = clienthead;

            while (temp->next != cur) {
                temp = temp->next;
            }
            temp->next = cur->next;
            delete cur;
            cout << "Deleted!!" << endl;
        }
        else {
            cout << "Id doesnt exist in linked list \n";
        }
    }
}

void LinkedList::displayEmployeeList() {

    Node* cur = emphead;

    while (cur != NULL) {
        cout << cur->getEmployee().getName() << " ";
        cout << cur->getEmployee().getId() << " ";
        cout << cur->getEmployee().getSalary() << " ";
        cout << cur->getEmployee().getProject() << " ";
        cout << cur->getEmployee().getJoiningDate() << " ";
        cout << cur->getEmployee().getPhone() << " ";
        cout << cur->getEmployee().getAddress() << " \n";
        cur = cur->next;
    }
    cout << endl;
}

void LinkedList::displayCliList() {

    Node* cur = clienthead;

    while (cur != NULL) {
        cout << cur->getClient().getName() << " ";
        cout << cur->getClient().getId() << " ";
        cout << cur->getClient().getPhone() << " ";
        cout << cur->getClient().getAddress() << " ";
        cout << cur->getClient().getProject_Id() << " \n";
        cur = cur->next;
    }
    cout << endl;
}

void LinkedList::updateSalary(int id, string name, double new_salary) {                //The old function was updatePrice
                                                                                       //Changed it into updateSalary
    Node* cur = emphead;                                                               //Also the parameters
    bool found = false;                                                                //if id and name are same the salary can be changed.
    if (emphead == NULL) {

        cout << "Linked list is empty" << endl;
    }
    else {
        while (cur != NULL) {
            if (cur->getEmployee().getId() == id && cur->getEmployee().getName() == name) {
                cur->getEmployee().setSalary(new_salary);
                found = true;
                break;
            }
            cur = cur->next;
        }
        if (!found) {
            cout << "Salary not found in linked iist.\n";
        }
    }
}

void LinkedList::updateClient(string name, int id, string phone, string address, int project_id)
{
    bool check = false;
    Node* cur = clienthead;
    while (cur != NULL) {
        if (cur->getClient().getId() == id) {
            check = true;
            break;
        }
        cur = cur->next;
    }
    if (check) {
        cur->getClient().setName(name);
        cur->getClient().setPhone(phone);
        cur->getClient().setAddress(address);
        cur->getClient().setProject_Id(project_id);
        cout << "database updated.\n";
    }
    else {
        cout << "The Empoyee that you are trying to access is either classified or doesnt exist. Check your id.\n";
    }
}


void LinkedList::swapNodes(Node* cur, Node* index) {
    Employee temp;
    temp.setName(cur->getEmployee().getName());
    temp.setId(cur->getEmployee().getId());
    temp.setSalary(cur->getEmployee().getSalary());
    temp.setProject(cur->getEmployee().getProject());
    temp.setJoiningDate(cur->getEmployee().getJoiningDate());
    temp.setPhone(cur->getEmployee().getPhone());
    temp.setAddress(cur->getEmployee().getAddress());
    cur->getEmployee().setName(index->getEmployee().getName());
    cur->getEmployee().setId(index->getEmployee().getId());
    cur->getEmployee().setSalary(index->getEmployee().getSalary());
	cur->getEmployee().setProject(index->getEmployee().getProject());
    cur->getEmployee().setJoiningDate(index->getEmployee().getJoiningDate());
    cur->getEmployee().setPhone(index->getEmployee().getPhone());
    cur->getEmployee().setAddress(index->getEmployee().getAddress());
    index->getEmployee().setName(temp.getName());
    index->getEmployee().setId(temp.getId());
    index->getEmployee().setSalary(temp.getSalary());
    index->getEmployee().setProject(temp.getProject());
    index->getEmployee().setJoiningDate(temp.getJoiningDate());
    index->getEmployee().setPhone(temp.getPhone());
    index->getEmployee().setAddress(temp.getAddress());
}

void LinkedList::swapCliNodes(Node* cur, Node* index) {
    Client temp;
    temp.setName(cur->getClient().getName());
    temp.setId(cur->getClient().getId());
    temp.setPhone(cur->getClient().getPhone());
    temp.setAddress(cur->getClient().getAddress());
    temp.setProject_Id(cur->getClient().getProject_Id());
    cur->getClient().setName(index->getClient().getName());
    cur->getClient().setId(index->getClient().getId());
    cur->getClient().setPhone(index->getClient().getPhone());
    cur->getClient().setAddress(index->getClient().getAddress());
    cur->getClient().setProject_Id(index->getClient().getProject_Id());
    index->getClient().setName(temp.getName());
    index->getClient().setId(temp.getId());
    index->getClient().setPhone(temp.getPhone());
    index->getClient().setAddress(temp.getAddress());
    index->getClient().setProject_Id(temp.getProject_Id());
}

void LinkedList::sortByNameAes() {

    Node* cur = emphead;
    Node* index = NULL;
    if (emphead == NULL) {

        cout << "Linked list empty, nothing to sort \n";
    }
    else {
        while (cur != NULL) {
            index = cur->next;
            while (index != NULL) {
                if (cur->getEmployee().getName() > index->getEmployee().getName()) {
                    swapNodes(cur, index);
                }
                index = index->next;
            }
            cur = cur->next;
        }
    }
}

void LinkedList::sortByCliNameAes() {

    Node* cur = clienthead;
    Node* index = NULL;
    if (clienthead == NULL) {

        cout << "Linked list empty, nothing to sort \n";
    }
    else {
        while (cur != NULL) {
            index = cur->next;
            while (index != NULL) {
                if (cur->getClient().getName() > index->getClient().getName()) {
                    swapCliNodes(cur, index);
                }
                index = index->next;
            }
            cur = cur->next;
        }
    }
}

void LinkedList::sortByNameDec() {

    Node* cur = emphead;
    Node* index = NULL;
    if (emphead == NULL) {

        cout << "Linked list empty, nothing to sort \n";
    }
    else {
        while (cur != NULL) {
            index = cur->next;
            while (index != NULL) {
                if (cur->getEmployee().getName() < index->getEmployee().getName()) {
                    swapNodes(cur, index);
                }
                index = index->next;
            }
            cur = cur->next;
        }
    }
}

void LinkedList::sortByCliNameDec() {

    Node* cur = clienthead;
    Node* index = NULL;
    if (clienthead == NULL) {

        cout << "Linked list empty, nothing to sort \n";
    }
    else {
        while (cur != NULL) {
            index = cur->next;
            while (index != NULL) {
                if (cur->getClient().getName() < index->getClient().getName()) {
                    swapCliNodes(cur, index);
                }
                index = index->next;
            }
            cur = cur->next;
        }
    }
}

size_t LinkedList::listSize() {

    Node* cur = emphead;

    size_t counter = 0;
    while (cur != NULL) {
        cur = cur->next;
        counter++;
    }
    return counter;
}

size_t LinkedList::ClilistSize() {

    Node* cur = clienthead;

    size_t counter = 0;
    while (cur != NULL) {
        cur = cur->next;
        counter++;
    }
    return counter;
}

void LinkedList::reverseLinkedList() {

    Node* cur = emphead;
    Node* temp = NULL;
    Node* prev = NULL;
    if (emphead == NULL) {
        cout << "Linked list empty, nothing to reverse.\n";
    }
    else if (emphead->next == NULL) {

        cout << "Only one element in List, nothing to reverse.\n";
    }
    else {
        while (cur != NULL) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        emphead = prev;
    }
}

void LinkedList::reverseCliLinkedList() {

    Node* cur = clienthead;
    Node* temp = NULL;
    Node* prev = NULL;
    if (clienthead == NULL) {
        cout << "Linked list empty, nothing to reverse.\n";
    }
    else if (clienthead->next == NULL) {

        cout << "Only one element in List, nothing to reverse.\n";
    }
    else {
        while (cur != NULL) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        clienthead = prev;
    }
}
