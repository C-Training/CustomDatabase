#include <iostream>
#include <string>
#include "Test.h"
#include "Activity.h"
using namespace std;

int main()
{

    Activity test;
    
    for (int i = 0; i < 10; i++) {
        test.setData("Talha", i, "fuckboi", 69, 9000000, "3 hours", "1/25/2021");
        test.enterToDatabasePrj();
    }
    test.deleteEndProjectDatabase();
    test.deleteEndProjectDatabase();
    test.deleteHeadProjectDatabase();
        test.displayDatabase();



    return 0;
}
