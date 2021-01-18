#include "Test.h"


Test::Test()
{
    LinkedList list1;
    bool tatti = 0;
    
    int randomNumber;

    srand(time(NULL));
    int n = 6;
    string randomString;
    
    //working
    for (int i = 0; i < 20000; i++) {
        randomString = printRandomString(n);
		randomNumber = rand();
        list1.addAtEnd(list1.listSize() + 1, randomString, randomNumber);
        testaddAtEnd(testlistSize() + 1, randomString, randomNumber);
        if (i % 1000 == 0) {
            cout << ".";
        }
    }
	if (!check(list1.getHead())) {
		tatti = 1;
	}
  
	//working
	for (int i = 0; i < 5000; i++) {
		randomString = printRandomString(n);
		randomNumber = rand();
		list1.addAtHead(list1.listSize() + 1, randomString, randomNumber);
		testaddAtHead(testlistSize() + 1, randomString, randomNumber);
		if (i % 1000 == 0) {
			cout << ".";
		}
	}
	if (!check(list1.getHead())) {
		tatti = 1;
	}

	//working
	for (int i = 15000; i < 24000; i++) {
		list1.deleteById(i);
		testdeleteById(i);
		if (i % 1000 == 0) {
			cout << ".";
		}
	}
	if (!check(list1.getHead())) {
		tatti = 1;
	}

    //working
    for (int i = 0; i < 15000; i++) {
        list1.deleteAtHead();
        testdeleteAtHead();
		if (i % 1000 == 0) {
			cout << ".";
		}
    }
	if (!check(list1.getHead())) {
		tatti = 1;
	}
    
    

    //working
    list1.reverseLinkedList();
    testreverseLinkedList();
	if (!check(list1.getHead())) {
		tatti = 1;
	}

    //working
	list1.sortByNameAes();
	testsortByNameAes();
	if (!check(list1.getHead())) {
		tatti = 1;
	}

    //working
	list1.sortByNameDec();
	testsortByNameDec();
	if (!check(list1.getHead())) {
		tatti = 1;
	}

}

string Test::printRandomString(int n)
{
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };

    string res = "";
    for (int i = 0; i < n; i++)
        res = res + alphabet[rand() % 26];

    return res;
}

bool Test::check(Node* obj) {
    string test_check = "Test";
    string pass_or_failed;
    testNumber++;
    int num = testNumber;
    test_check += to_string(num);
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
        pass_or_failed = " passed";
        cout << test_check + "........................." + pass_or_failed << endl;
    }
    else {
        pass_or_failed = " failed";
        cout << test_check + "........................." + pass_or_failed << endl;
    }

    //t1 = NULL;
    return noer;
}

void Test::testaddAtEnd(int id, string name, int price) {
    Node* new_node = new Node(id, name, price);
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

void Test::testaddAtHead(int id, string name, int price)
{
    Node* new_node = new Node(id, name, price);
    new_node->next = NULL;
    if (t1 == NULL) {
        t1 = new_node;
    }
    else {
        Node* temp = this->t1;
        t1 = new_node;
        t1->next = temp;
    }
}

void Test::testdeleteAtHead()
{
    if (t1 == NULL) {
        cout << "There is no linked list to delete" << endl;
    }
    else {
        Node* temp = t1;
        t1 = t1->next;
        delete temp;
    }
}

void Test::testdeleteById(int id)
{
    if (t1 == NULL) {
        cout << "linked list is empty \n";
    }
    else if (t1->getId() == id) {
        testdeleteAtHead();
    }
    else {
        Node* cur = t1;
        bool found = true;
        while (cur->getId() != id) {
            if (cur == NULL) {
                found = false;
                break;
            }
            cur = cur->next;
        }
        if (found) {
            Node* temp = t1;
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

void Test::testdisplayList()
{
    Node* cur = t1;
    while (cur != NULL) {
        cout << cur->getId() << " ";
        cout << cur->getName() << " ";
        cout << cur->getPrice() << " \n";
        cur = cur->next;
    }
    cout << endl;
}

void Test::testupdatePrice(int old_val, int new_val)
{
    Node* cur = t1;
    bool found = false;
    if (t1 == NULL) {
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

void Test::testswapNodes(Node* cur, Node* index) {
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

inline void Test::testsortByNameAes() {
    Node* cur = t1;
    Node* index = NULL;
    if (t1 == NULL) {
        cout << "Linked list empty, nothing to sort \n";
    }
    else {
        while (cur != NULL) {
            index = cur->next;
            while (index != NULL) {
                if (cur->getName() > index->getName()) {
                    testswapNodes(cur, index);
                }
                index = index->next;
            }
            cur = cur->next;
        }
    }
}

void Test::testsortByNameDec() {
    Node* cur = t1;
    Node* index = NULL;
    if (t1 == NULL) {
        cout << "Linked list empty, nothing to sort \n";
    }
    else {
        while (cur != NULL) {
            index = cur->next;
            while (index != NULL) {
                if (cur->getName() < index->getName()) {
                    testswapNodes(cur, index);
                }
                index = index->next;
            }
            cur = cur->next;
        }
    }
}

size_t Test::testlistSize() {
    Node* cur = t1;
    size_t counter = 0;
    while (cur != NULL) {
        cur = cur->next;
        counter++;
    }
    return counter;
}

void Test::testreverseLinkedList() {
    Node* cur = t1;
    Node* temp = NULL;
    Node* prev = NULL;
    if (t1 == NULL) {
        cout << "Linked list empty, nothing to reverse.\n";
    }
    else if (t1->next == NULL) {
        cout << "Only one element in List, nothing to reverse.\n";
    }
    else {
        while (cur != NULL) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        t1 = prev;
    }
}
