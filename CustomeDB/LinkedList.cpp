#include "LinkedList.h"



LinkedList::LinkedList()
{
 }


LinkedList::LinkedList(string fileName) {
    this->fileName = fileName;
    ifstream infile(fileName);
    if (infile.fail()) {
        cerr << "Error Opening File. \n";
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

Node* LinkedList::getProjectHead() {
    return prjhead;
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

void LinkedList::addAtHead(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date) {
    Node* temp = new Node(name, id, description, client_id, money_earned, deadline, complete_date);
    temp->next = prjhead;
    prjhead = temp;

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


void LinkedList :: addAtEnd(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date) {
    Node* temp = new Node(name, id, description, client_id, money_earned, deadline, complete_date);
    temp->next = NULL;
    if (prjhead == NULL) {
        prjhead = temp;
    }
    else {
        prjtail = prjhead;
        while (prjtail->next != NULL) {
            prjtail = prjtail->next;
        }
        prjtail->next = temp;
    }
}



void LinkedList::deleteAtEmployeeHead() {


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


void LinkedList::deleteAtHeadPrj() {

    if (prjhead == NULL) {
        cout << "There is no linked list to delete" << endl;
    }
    else {
        Node* temp = prjhead;
        prjhead = prjhead->next;

        delete temp;
    }
}

void LinkedList::deleteAtEndPrj() {
    if (prjhead == NULL) {
        cout << "LinkedList is already empty";
    }
    else if (prjhead->next == NULL) {
        prjhead = NULL;
    }
    else {
        Node* temp = prjhead;
        while (temp->next != NULL) {
            prjtail = temp;
            temp = temp->next;
        }
        prjtail->next = NULL;
        delete temp;
        }
}




void LinkedList::deleteByEmployeeId(int id) {


    if (emphead == NULL) {
        cout << "linked list is empty \n";
    }
    else if (emphead->getEmployee().getId() == id) {
        deleteAtEmployeeHead();
    }
    else {
        Node* cur = emphead;

        bool found = false;
        while (cur != NULL) {
            if (cur->getEmployee().getId() == id) {
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
        }
        else {
            cout << "Id doesnt exist in linked list \n";
        }
    }
}


void LinkedList::deleteByIdPrj(int id) {

    if (prjhead == NULL) {
        cout << "linked list is empty \n";
    }
      if (prjhead->prj.getid() == id) {
        deleteAtHeadPrj();
    }
    else {
        Node* cur = prjhead;

        bool found = false;
        while (cur != NULL) {
            if (cur->prj.getid() == id) {
                found = true;
                break;
            }
            cur = cur->next;
        }
        if (found) {

            Node* temp = prjhead;

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

void LinkedList::updateByIdPrj(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date)
{
    bool check = false;
    Node* cur = prjhead;
    while (cur != NULL) {
        if (cur->getProject().getid() == id) {
            check = true;
            break;
        }
        cur = cur->next;
    }
    if (check) {
        cur->prj.setname(name);
        cur->prj.setid(id);
        cur->prj.setdescription(description);
        cur->prj.setclient_id(client_id);
        cur->prj.setmoney_earned(money_earned);
        cur->prj.setdeadline(deadline);
        cur->prj.setcomplete_date(complete_date);

        cout << "database updated.\n";
    }
    if (!check) {
        cout << "We're sorry but this id doesn't exist. \n";
    }
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
void LinkedList::displayListPrj() {
    Node* temp = prjhead;
    while (temp != NULL) {
        cout << temp->getProject().getid() << " \n";
        cout << temp->getProject().getname() << " \n";
        cout << temp->getProject().getdescription() << " \n";
        cout << temp->getProject().getclient_id() << " \n";
        cout << temp->getProject().getmoney_earned() << " \n";
        cout << temp->getProject().getdeadline() << " \n";
        cout << temp->getProject().getcomplete_date() << " \n";
        cout << "\n";
        temp = temp->next;
    }
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
            if (cur->emp.getId() == id && cur->getEmployee().getName() == name) {
                cur->emp.setSalary(new_salary);
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

void LinkedList:: updateCliList() {
    Node* current = clienthead;
    string name, phone, address;
    int id = 0;
    int new_id = 0;
    int project_id = 0;
    cout << "Enter the id whose client data you want to change" << endl;
    cin >> id;
    cout << "Enter the name,id,phone,address and project id " << endl;
    cin >> name;
    cin >> new_id;
    cin >> phone;
    cin >> address;
    cin >> project_id;
    while ((current->next)!=NULL) {
        if ((current->getClient().getId())==id) {
            current->getClient().setName(name);
            current->getClient().setId(new_id);
            current->getClient().setPhone(phone);
            current->getClient().setAddress(address);
            current->getClient().setProject_Id(project_id);
            cout << "Updated Data" << endl;
        }else {
            current = current->next;
        }
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

void LinkedList::sortByEmployeeNameAes() {

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
                    swapEmployeeNodes(cur, index);
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

void LinkedList::sortByEmployeeNameDec() {

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



size_t LinkedList::employeeListSize() {
    Node* cur = emphead;

    size_t counter = 0;
    while (cur != NULL) {
        cur = cur->next;
        counter++;
        cout << "Linked list empty, nothing to sort \n";
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


size_t LinkedList::listSizeProj() {
    Node* temp = prjhead;
    size_t counter = 0;
    while (temp != NULL) {
        temp = temp->next;
        counter++;
    }
    return counter;
}


void LinkedList::reverseEmployeeLinkedList() {


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