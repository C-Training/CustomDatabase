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

void update_data(int id,int new_price) {
    struct Node* temp = head;
    while ((temp->ID)!=id) {
        temp = temp->next;
    }
    temp->price = new_price;
    cout << "New price of " << (temp->ID) << "is " << (temp->price) << endl;
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

void sort() {
    int a,c,d = 0;
    string k;
    struct Node* temp = NULL;
    struct Node* current = head;

    cout <<"Press 1 for ascending and 2 for descending"<< endl;
    cin >> a;
    if (a == 1) {
        while (current != NULL) {
            temp = current->next;
            while (temp != NULL) {
                if (current->ID > temp->ID) {
                    c = current->ID;
                    k = current->name;
                    d = current->price;
                    current->ID = temp->ID;
                    current->name = temp->name;
                    current->price = temp->price;
                    temp->ID = c;
                    temp->name = k;
                    temp->price =d;
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
                if (current->ID < temp->ID) {
                    c = current->ID;
                    k = current->name;
                    d = current->price;
                    current->ID = temp->ID;
                    current->name = temp->name;
                    current->price = temp->price;
                    temp->ID = c;
                    temp->name = k;
                    temp->price = d;
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

    //    void update_data(int old_price,int new_price) {
    //        int pos = 0;
    //
    //        if (head == NULL) {
    //            cout << "Linked list empty" << endl;
    //        }
    //
    //        current = head;
    //        while (current->next != NULL) {
    //            if (current->price == old_price) {
    //                current->data = new_price;
    //                cout << "Updated!!!" << endl;
    //            }
    //
    //            current = current->next;
    //        }
    //        cout << "not present" << endl;
    //    }
    //}


    int main() {
        string p, c;
        int a, entry = 0;
        cout << "How many entries you wanna do L" << endl;
        cin >> entry;

        for (int i = 0;i < entry;i++) {
            cout << "Enter the product then enter its price and lastly its ID" << endl;
            cin >> p;
            cin >> a;
            cin >> c;
            insert(a, p, c);
        }
        print();
        deletehead();
        print();
        //update_data();
        //print();

    return 0;
}

