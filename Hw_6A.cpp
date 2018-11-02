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
double get_radius(void);
void print_results(double radius, double circ, double area);
double calc_area(double);
double calc_circ(double);

int main() {
    double radius;
	double area, circ;
    // Display a welcome message
    welcome();
    // Get Radius
    radius = get_radius();
    // Perform Calculations
    circ = calc_circ(radius);
    area = calc_area(radius);

    // Display Results
    print_results(radius, circ, area);
    // Perform Calculations - second solution
    // call the calculateCircle function
    
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

double get_radius() {   //prompt user for radius
    double radius;  //radius
    do {
        cout << "Enter radius (must be > 0): ";
        cin  >> radius;
    } while (radius <= 0);
    return radius;
}

void print_results(double radius, double circ, double area) {  //output results
    cout << "\n\nRESULTS\n";
    cout << "\tRadius = " << radius << endl;
    cout << "\tCircumference = " << circ << endl;
    cout << "\tArea = " << area << endl;
}

double calc_area(double radius) {  //calculate area of circle
    double area;
    area = PI * radius * radius;
    return area;
}

double calc_circ(double radius) {  //calculate circumference of circle
    double circ;
    circ = 2 * radius * radius;
    return circ;
}
