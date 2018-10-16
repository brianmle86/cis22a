/**
   Constants, variables and arithmetic operators

   This program will output the circumference and area
   of the circle with a given radius.

   Brian Le
   Unix vim gcc
*/
#include <iostream>

using namespace std;

const double PI = 3.14;

int main()
{
	double circumference;                // definition of circumference
    double radius = 5.4;                 // definition and initialization of the radius
    double area;                        // definition of area of circle
    
    // Calculations Section
    circumference = 2 * PI * radius;    // computes circumference

    area = PI * radius * radius;                       // computes area
    
    // Display Results Section
    // Fill in the code for the cout statement that will output (with description)
    // the radius
    cout << "The radius is " << radius << " units\n";

    // Fill in the code for the cout statement that will output (with description)
    // the circumference
    cout << "The circumference is " << circumference << " units\n";

    // Fill in the code for the cout statement that will output (with description)
    // the area of the circle
    cout << "The area is " << area << " units^2\n";

    return 0;
}
/*********************************************************************************
The radius is 5.4 units
The circumference is 33.912 units
The area is 91.5624 units^2
*/
