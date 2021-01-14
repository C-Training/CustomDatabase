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
        int id;
        string name;
        int price;
        while (infile >> id >> name >> price) {
            addAtEnd(id, name, price);
        }
        infile.close();
    }
}
LinkedList::~LinkedList() {
    ofstream outfile;
    outfile.open(fileName, ios::out | ios::trunc);
    Node* cur = head;
    while (cur != NULL) {
        outfile << cur->getId() << " ";
        outfile << cur->getName() << " ";
        outfile << cur->getPrice() << endl;
        cur = cur->next;
    }
    outfile.close();
}

Node* LinkedList::getHead()
{
    return head;
}

void LinkedList::addAtHead(int id, string name, int price) {
    Node* new_node = new Node(id, name, price);
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    }
    else {
        Node* temp = head;
        head = new_node;
        head->next = temp;
    }
}

void LinkedList::addAtEnd(int id, string name, int price) {

    Node* new_node = new Node(id, name, price);
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    }
    else {
        Node* cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }

}
void LinkedList::deleteAtHead() {
    if (head == NULL) {
        cout << "There is no linked list to delete" << endl;
    }
    else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::deleteById(int id) {
    if (head == NULL) {
        cout << "linked list is empty \n";
    }
    else if (head->getId() == id) {
        deleteAtHead();
    }
    else {
        Node* cur = head;
        bool found = true;
        while (cur->getId() != id) {
            if (cur == NULL) {
                found = false;
                break;
            }
            cur = cur->next;
        }
        if (found) {
            Node* temp = head;
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
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->getId() << " ";
        cout << cur->getName() << " ";
        cout << cur->getPrice() << " \n";
        cur = cur->next;
    }
    cout << endl;
}

void LinkedList::updatePrice(int old_val, int new_val) {
    Node* cur = head;
    bool found = false;
    if (head == NULL) {
        cout << "Linled list is empty" << endl;
    }
    else {
        while (cur != NULL) {
            if (cur->getPrice() == old_val) {
                cur->setPrice(new_val);
                found = true;
                break;
            }
            cur = cur->next;
        }
        if (!found) {
            cout << "Price not found in linked iist.\n";
        }
    }
}

void LinkedList::swapNodes(Node* cur, Node* index) {
    Item temp;
    temp.id = cur->getId();
    temp.name = cur->getName();
    temp.price = cur->getPrice();
    cur->setId(index->getId());
    cur->setName(index->getName());
    cur->setPrice(index->getPrice());
    index->setId(temp.id);
    index->setName(temp.name);
    index->setPrice(temp.price);
}

void LinkedList::sortByNameAes() {
    Node* cur = head;
    Node* index = NULL;
    if (head == NULL) {
        cout << "Linked list empty, nothing to sort \n";
    }
    else {
        while (cur != NULL) {
            index = cur->next;
            while (index != NULL) {
                if (cur->getName() > index->getName()) {
                    swapNodes(cur, index);
                }
                index = index->next;
            }
            cur = cur->next;
        }
    }
}

void LinkedList::sortByNameDec() {
    Node* cur = head;
    Node* index = NULL;
    if (head == NULL) {
        cout << "Linked list empty, nothing to sort \n";
    }
    else {
        while (cur != NULL) {
            index = cur->next;
            while (index != NULL) {
                if (cur->getName() < index->getName()) {
                    swapNodes(cur, index);
                }
                index = index->next;
            }
            cur = cur->next;
        }
    }
}

size_t LinkedList::listSize() {
    Node* cur = head;
    size_t counter = 0;
    while (cur != NULL) {
        cur = cur->next;
        counter++;
    }
    return counter;
}

void LinkedList::reverseLinkedList() {
    Node* cur = head;
    Node* temp = NULL;
    Node* prev = NULL;
    if (head == NULL) {
        cout << "Linked list empty, nothing to reverse.\n";
    }
    else if (head->next == NULL) {
        cout << "Only one element in List, nothing to reverse.\n";
    }
    else {
        while (cur != NULL) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        head = prev;
    }
}