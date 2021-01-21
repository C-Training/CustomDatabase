#include "LinkedList.h"



LinkedList::LinkedList() {
    cout << "linked list created.\n";
}

LinkedList::LinkedList(string fileName) {
    this->fileName = fileName;
    ifstream infile(fileName);
    if (!infile) {
        cout << "No such File. \n";
    }
    else {
        cout << "i was here" << endl;
        string name;
        int id;
        string phone; 
        string address;
        int project_id;
        while (infile >> name >> id >> phone>>address>>project_id) {
            addAtEnd(name, id, phone, address, project_id);
        }
        infile.close();
    }
}
LinkedList::~LinkedList() {
    ofstream outfile;
    outfile.open(fileName, ios::out | ios::trunc);

    Node* cur = clienthead;

    while (cur != NULL) {
        outfile << cur->getClient().getname() << " ";
        outfile << cur->getClient().getid() << " ";
        outfile << cur->getClient().getphone() << " ";
        outfile << cur->getClient().getaddress() << " ";
        outfile << cur->getClient().getproject_id() << endl;
        cur = cur->next;
    }
    outfile.close();
}

Node* LinkedList::getclientHead()
{
    return clienthead;
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
            if (cur->getClient().getid() == id ) {
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

//void LinkedList::updatePrice(int old_val, int new_val) {
//
//    Node* cur = head;
//    bool found = false;
//    if (head == NULL) {
//
//        cout << "Linled list is empty" << endl;
//    }
//    else {
//        while (cur != NULL) {
//            if (cur->getPrice() == old_val) {
//                cur->setPrice(new_val);
//                found = true;
//                break;
//            }
//            cur = cur->next;
//        }
//        if (!found) {
//            cout << "Price not found in linked iist.\n";
//        }
//    }
//}

void LinkedList::swapNodes(Node* cur, Node* index) {
    Client temp;    
    temp.setname(cur->getClient().getname());
    temp.setid(cur->getClient().getid());
    temp.setphone(cur->getClient().getphone());
    temp.setaddress(cur->getClient().getaddress());
    temp.setproject_id(cur->getClient().getproject_id());
    cur->getClient().setname(index->getClient().getname());
    cur->getClient().setid(index->getClient().getid());
    cur->getClient().setphone(index->getClient().getphone());
    cur->getClient().setaddress(index->getClient().getaddress());
    cur->getClient().setproject_id(index->getClient().getproject_id());
    index->getClient().setname(temp.getname());
    index->getClient().setid(temp.getid());
    index->getClient().setphone(temp.getphone());
    index->getClient().setaddress(temp.getaddress());
    index->getClient().setproject_id(temp.getproject_id());
}

void LinkedList::sortByNameAes() {

    Node* cur = clienthead;
    Node* index = NULL;
    if (clienthead == NULL) {

        cout << "Linked list empty, nothing to sort \n";
    }
    else {
        while (cur != NULL) {
            index = cur->next;
            while (index != NULL) {
                if (cur->getClient().getname() > index->getClient().getname()) {
                    swapNodes(cur, index);
                }
                index = index->next;
            }
            cur = cur->next;
        }
    }
}

void LinkedList::sortByNameDec() {

    Node* cur = clienthead;
    Node* index = NULL;
    if (clienthead == NULL) {

        cout << "Linked list empty, nothing to sort \n";
    }
    else {
        while (cur != NULL) {
            index = cur->next;
            while (index != NULL) {
                if (cur->getClient().getname() < index->getClient().getname()) {
                    swapNodes(cur, index);
                }
                index = index->next;
            }
            cur = cur->next;
        }
    }
}

size_t LinkedList::listSize() {

    Node* cur = clienthead;

    size_t counter = 0;
    while (cur != NULL) {
        cur = cur->next;
        counter++;
    }
    return counter;
}

void LinkedList::reverseLinkedList() {

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