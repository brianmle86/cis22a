/**
 PART A
 
 Find and fix the errors
 Run the program once and save the output as a comment at the end
 of the source file.
 
Brian Le
Unix vim gcc
*/

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int begInv;
    int sold;
    int store1, store2, store3;

    // Get the beginning inventory for all the stores.
    cout << "One week ago, 3 new widget stores opened \n";
    cout << "at the same time with the same beginning \n";
    cout << "inventory. What was the beginning inventory? ";
    cin >> begInv;

    // Set each store's inventory.
    store1 = store2 = store3 = begInv;

    // Get the number of widgets sold at store 1.
    cout << "How many widgets has store 1 sold? ";
    cin >> sold;
    store1 -= sold; // Adjust store 1's inventory.

    // Get the number of widgets sold at store 2.
    cout << "How many widgets has store 2 sold? ";
    cin >> sold;
    store2 -= sold; // Adjust store 2's inventory.

    // Get the number of widgets sold at store 3.
    cout << "How many widgets has store 3 sold? ";
    cin >> sold;
    store3 -= sold; // Adjust store 3's inventory.

    // Display each store's current inventory.
    cout << "\nThe current inventory of each store:\n";
    cout << "Store 1: " << store1 << endl;
    cout << "Store 2: " << store2 << endl;
    cout << "Store 3: " << store3 << endl;
    return 0;
}
/***********************************************************************
One week ago, 3 new widget stores opened 
at the same time with the same beginning 
inventory. What was the beginning inventory? 50
How many widgets has store 1 sold? 1
How many widgets has store 2 sold? 2
How many widgets has store 3 sold? 3

The current inventory of each store:
Store 1: 49
Store 2: 48
Store 3: 47



One week ago, 3 new widget stores opened 
at the same time with the same beginning 
inventory. What was the beginning inventory? 75 
How many widgets has store 1 sold? 14
How many widgets has store 2 sold? 32
How many widgets has store 3 sold? 75

The current inventory of each store:
Store 1: 61
Store 2: 43
Store 3: 0
 


One week ago, 3 new widget stores opened
at the same time with the same beginning
inventory. What was the beginning inventory? 100
How many widgets has store 1 sold? -1
How many widgets has store 2 sold? 0
How many widgets has store 3 sold? -0

The current inventory of each store:
Store 1: 101
Store 2: 100
Store 3: 100

 */
