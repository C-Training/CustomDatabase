#include "linkedlist.h"

void linkedlist::update_data(int id, int new_price) {
    struct Node* temp = head;
    while ((temp->data.ID) != id) {
        temp = temp->next;
    }
    temp->data.price = new_price;
    cout << "New price of " << (temp->data.ID) << "is " << (temp->data.price) << endl;
}

void linkedlist::print() {
    struct Node* temp = head;
    while (temp != NULL) {
        cout << endl;
        cout << "The price is :- " << temp->data.price << endl;
        cout << "The name of the product is :- " << temp->data.name << endl;
        cout << "The ID of the product is :- " << temp->data.ID << endl;
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
            MyFile << "Name is " << temp->data.name << endl;
            MyFile << "Price is " << temp->data.price << endl;
            MyFile << "ID is " << temp->data.ID << endl;
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
                if (current->data.ID > temp->data.ID) {
                    c = current->data.ID;
                    k = current->data.name;
                    d = current->data.price;
                    current->data.ID = temp->data.ID;
                    current->data.name = temp->data.name;
                    current->data.price = temp->data.price;
                    temp->data.ID = c;
                    temp->data.name = k;
                    temp->data.price = d;
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
                if (current->data.ID < temp->data.ID) {
                    c = current->data.ID;
                    k = current->data.name;
                    d = current->data.price;
                    current->data.ID = temp->data.ID;
                    current->data.name = temp->data.name;
                    current->data.price = temp->data.price;
                    temp->data.ID = c;
                    temp->data.name = k;
                    temp->data.price = d;
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
        cout << head->data.price << " is removed." << endl;
        cout << head->data.name << " is removed." << endl;
        cout << head->data.ID << " is removed." << endl;
        head = head->next;
        delete(temp);
    }
}
