#include "LinkedList.h"



LinkedList::LinkedList()
{
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

//void LinkedList::deleteAtHead() {
//
//    if (clienthead == NULL) {
//        cout << "There is no linked list to delete" << endl;
//    }
//    else {
//        Node* temp = clienthead;
//        clienthead = clienthead->next;
//
//        delete temp;
//    }
//}

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



//void LinkedList::deleteById(int id) {
//
//    if (emphead == NULL) {
//        cout << "linked list is empty \n";
//    }
//    else if (emphead->getEmployee().getId() == id) {
//        deleteAtHead();
//    }
//    else {
//        Node* cur = emphead;
//
//        bool found = false;
//        while (cur != NULL) {
//            if (cur->getEmployee().getId() == id ) {
//                found = true;
//                break;
//            }
//            cur = cur->next;
//        }
//        if (found) {
//
//            Node* temp = emphead;
//
//            while (temp->next != cur) {
//                temp = temp->next;
//            }
//            temp->next = cur->next;
//            delete cur;
//        }
//        else {
//            cout << "Id doesnt exist in linked list \n";
//        }
//    }
//}

void LinkedList::deleteById(int id) {

    if (clienthead == NULL) {
        cout << "linked list is empty \n";
    }
    else if (clienthead->getClient().getid() == id) {
        deleteAtHead();
    }
    else {
        Node* cur = clienthead;

        bool found = false;
        while (cur != NULL) {
            if (cur->getClient().getid() == id) {
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

void LinkedList::updateByIdPrj() {

    if (prjhead == NULL) {
        cout << "We're sorry but this linked list has same number of entries as you have girls";
    }
    else {
        cout << "Enter the id that you want to update : ";
        int id;
        cin >> id;
        Node* temp = prjhead;
        bool found = false;
        while (temp != NULL) {
            if (temp->prj.getid() == id) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (found) {
            cout << "What do you want to update in this class ? \n";
            cout << "Press 1 to update name \n";
            cout << "Press 2 to update description \n";
            cout << "Press 3 to update client_id \n";
            cout << "Press 4 to update money earned \n";
            cout << "Press 5 to update deadline \n";
            int input;
            cin >> input;

            if (input == 1) {
                string name;
                cout << " enter the new name : ";
                cin >> name;
                temp->prj.setname(name);
            }
            else if (input == 2) {
                string description;
                cout << " enter the new description : ";
                cin >> description;
                temp->prj.setdescription(description);
            }
            else if (input == 3) {
                int client_id;
                cout << " enter the new client_id : ";
                cin >> client_id;
                temp->prj.setclient_id(client_id);
            }
            else if (input == 4) {
                string money_earned;
                cout << " enter the new amount of money earned : ";
                cin >> money_earned;
                temp->prj.setmoney_earned(money_earned);
            }
            else if (input == 5) {
                string deadline;
                cout << " enter the new deadline : ";
                cin >> deadline;
                temp->prj.setdeadline(deadline);
            }
            else {
                cout << "Choose betweem given numbers \n";
            }
        }
        if (!found) {
            cout << "This id is not present in database. \n";
        }

    }
}


//void LinkedList::displayList() {
//
//    Node* cur = emphead;
//
//    while (cur != NULL) {
//        cout << cur->getEmployee().getName() << " ";
//        cout << cur->getEmployee().getId() << " ";
//        cout << cur->getEmployee().getSalary() << " ";
//        cout << cur->getEmployee().getProject() << " ";
//        cout << cur->getEmployee().getJoiningDate() << " ";
//        cout << cur->getEmployee().getPhone() << " ";
//        cout << cur->getEmployee().getAddress() << " \n";
//        cur = cur->next;
//    }
//    cout << endl;
//}

void LinkedList::displayList() {

    Node* cur = clienthead;

    while (cur != NULL) {
        cout << cur->getClient().getname() << " ";
        cout << cur->getClient().getid() << " ";
        cout << cur->getClient().getphone() << " ";
        cout << cur->getClient().getaddress() << " ";
        cout << cur->getClient().getproject_id() << " \n";
        cur = cur->next;
    }
    cout << endl;
}

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



//void LinkedList::swapNodes(Node* cur, Node* index) {
//    Client temp;
//    temp.setname(cur->getClient().getname());
//    temp.setid(cur->getClient().getid());
//    temp.setphone(cur->getClient().getphone());
//    temp.setaddress(cur->getClient().getaddress());
//    temp.setproject_id(cur->getClient().getproject_id());
//    cur->getClient().setname(index->getClient().getname());
//    cur->getClient().setid(index->getClient().getid());
//    cur->getClient().setphone(index->getClient().getphone());
//    cur->getClient().setaddress(index->getClient().getaddress());
//    cur->getClient().setproject_id(index->getClient().getproject_id());
//    index->getClient().setname(temp.getname());
//    index->getClient().setid(temp.getid());
//    index->getClient().setphone(temp.getphone());
//    index->getClient().setaddress(temp.getaddress());
//    index->getClient().setproject_id(temp.getproject_id());
//}

//void LinkedList::sortByNameAes() {
//
//    Node* cur = emphead;
//    Node* index = NULL;
//    if (emphead == NULL) {
//
//        cout << "Linked list empty, nothing to sort \n";
//    }
//    else {
//        while (cur != NULL) {
//            index = cur->next;
//            while (index != NULL) {
//                if (cur->getEmployee().getName() > index->getEmployee().getName()) {
//                    swapNodes(cur, index);
//                }
//                index = index->next;
//            }
//            cur = cur->next;
//        }
//    }
//}

//void LinkedList::sortByNameAes() {
//
//    Node* cur = clienthead;
//    Node* index = NULL;
//    if (clienthead == NULL) {
//
//        cout << "Linked list empty, nothing to sort \n";
//    }
//    else {
//        while (cur != NULL) {
//            index = cur->next;
//            while (index != NULL) {
//                if (cur->getClient().getname() > index->getClient().getname()) {
//                    swapNodes(cur, index);
//                }
//                index = index->next;
//            }
//            cur = cur->next;
//        }
//    }
//}
//
//void LinkedList::sortByNameDec() {
//
//    Node* cur = emphead;
//    Node* index = NULL;
//    if (emphead == NULL) {
//
//        cout << "Linked list empty, nothing to sort \n";
//    }
//    else {
//        while (cur != NULL) {
//            index = cur->next;
//            while (index != NULL) {
//                if (cur->getEmployee().getName() < index->getEmployee().getName()) {
//                    swapNodes(cur, index);
//                }
//                index = index->next;
//            }
//            cur = cur->next;
//        }
//    }
//}
//
//void LinkedList::sortByNameDec() {
//
//    Node* cur = clienthead;
//    Node* index = NULL;
//    if (clienthead == NULL) {
//
//        cout << "Linked list empty, nothing to sort \n";
//    }
//    else {
//        while (cur != NULL) {
//            index = cur->next;
//            while (index != NULL) {
//                if (cur->getClient().getname() < index->getClient().getname()) {
//                    swapNodes(cur, index);
//                }
//                index = index->next;
//            }
//            cur = cur->next;
//        }
//    }
//}

size_t LinkedList::listSize() {

    Node* cur = emphead;

    size_t counter = 0;
    while (cur != NULL) {
        cur = cur->next;
        counter++;
    }
    return counter;
}

//size_t LinkedList::listSize() {
//
//    Node* cur = clienthead;
//
//    size_t counter = 0;
//    while (cur != NULL) {
//        cur = cur->next;
//        counter++;
//    }
//    return counter;
//}

size_t LinkedList::listSizeProj() {
    Node* temp = prjhead;
    size_t counter = 0;
    while (temp != NULL) {
        temp = temp->next;
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

//void LinkedList::reverseLinkedList() {
//
//    Node* cur = clienthead;
//    Node* temp = NULL;
//    Node* prev = NULL;
//    if (clienthead == NULL) {
//        cout << "Linked list empty, nothing to reverse.\n";
//    }
//    else if (clienthead->next == NULL) {
//
//        cout << "Only one element in List, nothing to reverse.\n";
//    }
//    else {
//        while (cur != NULL) {
//            temp = cur->next;
//            cur->next = prev;
//            prev = cur;
//            cur = temp;
//        }
//        clienthead = prev;
//    }
//}