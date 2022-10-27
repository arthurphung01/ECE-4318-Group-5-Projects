// Midterm1Question1HugeInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "myHugeInteger.h"
using namespace std;

myHugeInteger m;

int main()
{
    myHugeInteger test1 = myHugeInteger(4317);
    myHugeInteger test2 = myHugeInteger(-4318);
    myHugeInteger test3 = m.addhi(test1, test2);
    cout << "The sum of " << test1.toString() << " and " << test2.toString() << " is " << test3.toString() << "\n";
    test3 = m.mulhi(test1, test2);
    cout << "The product of " << test1.toString() << " and " << test2.toString() << " is " << test3.toString() << "\n";

    // Test 1: 50 factorial
    test3 = myHugeInteger(1);
    for (int i = 1; i < 51; i++)
    {
        test1 = myHugeInteger(i);
        test3 = m.mulhi(test3, test1);
    }
    cout << "50 factorial is equal to " << test3.toString() << "\n";
    cout << "The amount of digits in 50 factorial is " << test3.numberOfDigits() << "\n";

    // Test 2: Digits in 1000 factorial.
    test3 = myHugeInteger(1);
    for (int i = 1; i < 1001; i++)
    {
        test1 = myHugeInteger(i);
        test3 = m.mulhi(test3, test1);
    }
    cout << "The amount of digits in 1000 factorial is " << test3.numberOfDigits() << "\n";

    // Test 3: 2^63 - 1.
    test3 = myHugeInteger(1);
    test1 = myHugeInteger(2);
    for (int i = 1; i < 64; i++)
    {
        test3 = m.mulhi(test3, test1);
    }
    test3 = m.subhi(test3, myHugeInteger(1));
    cout << "The value of 2^63 - 1 is " << test3.toString() << ", and contains " << test3.numberOfDigits() << " digits.";

    /*cout << "\n";
    test3 = m.subhi(test1, test2);
    test3.printHugeInteger();
    cout << "\n" << test3.numberOfDigits() << "\n";
    test1 = myHugeInteger(-32871);
    test2 = myHugeInteger(49238);
    test3 = m.mulhi(test1, test2);
    test3.printHugeInteger();
    cout << "\n";*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
