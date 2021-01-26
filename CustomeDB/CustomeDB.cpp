#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Test.h"
#include "Activity.h"
using namespace std;

int main()
{
    Activity test;
    test.setdata("hamza",23,"+928383","Abc town",43);
    test.entertoclidatabase();
    test.displaydatabase();
    //Test ();
    return 0;
}
