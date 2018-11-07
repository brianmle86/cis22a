/**~*~*~*~*~*~
   Project 6A: - in class exercise
 
   Defining and using functions in a C++ program:

       void welcome(void);                          // No paramaters, no return value
       void farewell(void);
       void printCircle(double, double, double);    // PASS BY VALUE
       double getRadius(void);                      // return a value
       double calcArea(double);                     // receive a value and return a value
       double calcCirc(double);
 
       double calculateCircle(double, &double, &double); // PASS BY REFERENCE
 
   This program will output the circumference and area
   of a circle with a given radius.
 
   NAME: Brian Le
 
*~**/

#include <iostream>

using namespace std;

const  double PI = 3.14;

void welcome(void);
void farewell(void);
double getRadius(void);
void printResults(double radius, double circ, double area);
double calcArea(double);
double calcCirc(double);
void calcCircle(double, double &, double &);
int main() {
    double radius;
	double area, circ;
    // Display a welcome message
    welcome();
    // Get Radius
    radius = getRadius();
    // Perform Calculations
    circ = calcCirc(radius);
    area = calcArea(radius);

    // Display Results
    printResults(radius, circ, area);
    // Perform Calculations - second solution
    // call the calculateCircle function
    area = circ = 0;
    calcCircle(radius, area, circ); //call
    // Display Results again, after the second calculation
    // call the printCircle function again

    // Display an "end of the program" message
    farewell();
   return 0;
}

void welcome() {   //welcome user
    cout << "WELCOME to the CIRCLE calculator!\n\n"
         << "This program will output the\n"
         << "\tcircumference and\n"
         << "\tarea\n"
         << "of a circle with a given radius.\n\n";
}

void farewell() {   //farewell to user
    cout << "\n\n"
         << "\t ~~*~~ The END ~~*~~ \n\n"
         << "\t        ~~*~~ \n"
         << "\t      Thank you\n\tfor using my program!\n";
}

double getRadius() {   //prompt user for radius
    double radius;  //radius
    do {
        cout << "Enter radius (must be > 0): ";
        cin  >> radius;
    } while (radius <= 0);
    return radius;
}

void printResults(double radius, double circ, double area) {  //output results
    cout << "\n\nRESULTS\n";
    cout << "\tRadius = " << radius << endl;
    cout << "\tCircumference = " << circ << endl;
    cout << "\tArea = " << area << endl;
}

double calcArea(double radius) {  //calculate area of circle
    double area;
    area = PI * radius * radius;
    return area;
}

double calcCirc(double radius) {  //calculate circumference of circle
    double circ;
    circ = 2 * PI * radius;
    return circ;
}

void calcCircle(double radius, double &area, double &circ) {
    area = 2 * radius * radius;
    circ = 2 * PI * radius;
}




