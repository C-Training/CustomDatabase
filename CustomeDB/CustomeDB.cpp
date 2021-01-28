#include <iostream>
#include <string>
#include "Test.h"
#include "Activity.h"
#include "LinkedList.h"
#include "Display.h"
using namespace std;

int main()
{

    Activity test;
    
    for (int i = 1; i < 6; i++) {
        test.setData("Talha", i, "fuckboi", 69, "9000000", "3 hours", "1/25/2021");
        test.enterToDatabasePrj();
    }
    //test.deleteHeadProjectDatabase();
    //test.deleteHeadProjectDatabase();
    //test.deleteEndProjectDatabase();
    //test.deleteByIdPrj(2);
    //test.displayDatabase();

    //test.updateByIdPrj();

    test.display();




    return 0;
}
