#include <iostream>
#include "LinkedList.h"

using namespace std;




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
    return 0;
}
