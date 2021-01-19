#include <iostream>
#include "linkedlist.h"
using namespace std;


int main() {
    string p;
    int a, c, entry = 0;
    cout << "How many entries you wanna do L" << endl;
    cin >> entry;
    linkedlist L;

    for (int i = 0;i < entry;i++) {
        cout << "Enter the product then enter its price and lastly its ID" << endl;
        cin >> p;
        cin >> a;
        cin >> c;
        L.insert(a, p, c);
    }
    L.print();
    //update_price(3,23);
    //sort();
    //reverse();
    //size();
    L.display();
    //print();
    L.display();

    return 0;
}

