#include "linkedlist.h"


void linkedlist::update_data(int id, int new_price) {
    struct Node* temp = head;
    while ((temp->getid()) != id) {
        temp = temp->next;
    }
    temp->setprice(new_price);
    cout << "New price of " << (temp->getid()) << "is " << (temp->getprice()) << endl;
}

void linkedlist::print() {
    struct Node* temp = head;
    while (temp != NULL) {
        cout << endl;
        cout << "The price is :- " << temp->getprice() << endl;
        cout << "The name of the product is :- " << temp->getname() << endl;
        cout << "The ID of the product is :- " << temp->getid() << endl;
        temp = temp->next;
    }
}

void linkedlist::display() {
    int a = 0;
    string myText;
    struct Node* temp = head;
    cout << endl;
    cout << "1 to write in new file and 2 to display contents of old file" << endl;
    cin >> a;
    if (a == 1) {
        ofstream MyFile("L.txt");
        while (temp != NULL) {
            MyFile << "Name is " << temp->getname() << endl;
            MyFile << "Price is " << temp->getprice() << endl;
            MyFile << "ID is " << temp->getid() << endl;
            temp = temp->next;
        }
        MyFile.close();
    }
    else if (a == 2) {
        ifstream MyReadFile("L.txt");
        while (getline(MyReadFile, myText)) {
            cout << myText << endl;
        }
        MyReadFile.close();
    }
}

void linkedlist::reverse() {
    struct Node* temp = head;
    struct Node* next = head;
    struct Node* prev = NULL;

    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}

void linkedlist::sort() {
    int a, c, d = 0;
    string k;
    struct Node* temp = NULL;
    struct Node* current = head;

    cout << "Press 1 for ascending and 2 for descending" << endl;
    cin >> a;
    if (a == 1) {
        while (current != NULL) {
            temp = current->next;
            while (temp != NULL) {
                if (current->getid() > temp->getid()) {
                    c = current->getid();
                    k = current->getname();
                    d = current->getprice();
                    current->setid(temp->getid());
                    current->setname(temp->getname());
                    current->setprice(temp->getprice());
                    temp->setid(c);
                    temp->setname(k);
                    temp->setprice(d);
                }
                temp = temp->next;
            }
            current = current->next;
        }
    }
    else if (a == 2) {
        while (current != NULL) {
            temp = current->next;
            while (temp != NULL) {
                if (current->getid() < temp->getid()) {
                    c = current->getid();
                    k = current->getname();
                    d = current->getprice();
                    current->setid(temp->getid());
                    current->setname(temp->getname());
                    current->setprice(temp->getprice());
                    temp->setid(c);
                    temp->setname(k);
                    temp->setprice(d);
                }
                temp = temp->next;
            }
            current = current->next;
        }
    }
    else {
        cout << "Wrong option L" << endl;
    }

}

void linkedlist::size() {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout << "The size of the L linked list is " << count << endl;
}

void linkedlist::deletehead() {
    if (head == NULL) {
        cout << "Empty" << endl;
    }
    else {
        Node* temp = head;
        cout << endl;
        cout << head->getprice() << " is removed." << endl;
        cout << head->getname() << " is removed." << endl;
        cout << head->getid() << " is removed." << endl;
        head = head->next;
        delete(temp);
    }
}
