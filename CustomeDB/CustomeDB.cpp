#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

class Test {
public:
    Node* t1 = NULL;
    Test() {
        LinkedList list1;

        bool tatti = 0;
        for (int i = 0; i < 10; i++) {
            list1.addAtEnd(i, "talha", i + 1);
            testaddAtEnd(i , "talha", i+1);
        }
        if (!check(list1.getHead())) {
            tatti = 1;
        }

        if (tatti) {
            cout << "Blah blah failed";
        }
        else {
            cout << "ggez";
        }
    }

    bool check(Node* obj) {
        bool noer = 1;
        Node* cur = this->t1;
        Node* temp = obj;
        while (cur->next != NULL && temp->next != NULL)
        {
            if (cur->getId() == temp->getId() && cur->getName() == temp->getName() && cur->getPrice() == temp->getPrice()) {
                cur = cur->next;
                temp = temp->next;
            }
            else {
                cout << "Lul your data is not inserted correctly" << endl;
                noer = 0;
                break;
            }
        }
        if (noer) {
            cout << "Test 1 pass" << endl;
        }

        t1 = NULL;
        return noer;
    }

    void testaddAtEnd(int id, string name, int price) {
        Node* new_node = new Node(id, name, price);
        new_node->setId(id);
        new_node->setName(name);
        new_node->setPrice(price);
        new_node->next = NULL;
        if (this->t1 == NULL) {
            this->t1 = new_node;
        }
        else {
            Node* cur = this->t1;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = new_node;
        }
    }
};



int main()
{
    LinkedList l1("myFile.txt");
    /*l1.addAtEnd(1, "talha", 20);
    l1.addAtEnd(2, "haseed", 10);
    l1.addAtEnd(3, "bats", 25);*/
    l1.displayList();
    LinkedList l2("newFile.txt");
    /*l2.addAtEnd(4, "Abad", 30);*/
    l2.displayList();

    Test();

    return 0;
}
