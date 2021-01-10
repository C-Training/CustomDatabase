#include <iostream>
#include <string>
using namespace std;

struct Node {
    int price;
    int ID;
    string name;
    Node* next;
};

struct Node* head = NULL;


void insert(int prc, string nme, int id) {
    struct Node* newNode = new Node;
    newNode->price = prc;
    newNode->name = nme;
    newNode->ID = id;
    newNode->next = head;
    head = newNode;
}

void print() {
    struct Node* temp = head;
    while (temp != NULL) {
        cout << endl;
        cout << "The price is :- " << temp->price << endl;
        cout << "The name of the product is :- " << temp->name << endl;
        cout << "The ID of the product is :- " << temp->ID << endl;
        temp = temp->next;
    }
}


void deletehead() {
    if (head == NULL) {
        cout << "Empty" << endl;
    }
    else {
        cout << endl;
        cout << head->price << " is removed." << endl;
        cout << head->name << " is removed." << endl;
        cout << head->ID << " is removed." << endl;
        head = head->next;
    }

    
}

void update_data(int idval, int price) {
    struct Node* temp = head;
    while (temp->ID != idval) {
        temp = temp->next;
    }
    temp->price = price;
}

int main() {
    //string p;
    //int c;
    //int a, entry = 0;
    //cout << "How many entries you wanna do L" << endl;
    //cin >> entry;

    //for (int i = 0;i < entry;i++) {
    //    cout << "Enter the product then enter its price and lastly its ID" << endl;
    //    cin >> p;
    //    cin >> a;
    //    cin >> c;
    //    insert(a, p, c);
    //}
    insert(12,"k",34);
    insert(34,"ab",32);
    insert(99,"asv",1);
    insert(99,"asvs",2);
    insert(99,"asasda",212);
    insert(99,"aswe",211);
    insert(99,"as231",221);
    insert(99,"asada",241);
    update_data(211,110);
    print();
    //update_data();
    //print();

    return 0;
}

////////////////////////////////////////////////////////