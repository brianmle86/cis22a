/**
 PART C
 
 Write a program that will do the following steps (pseudo-code):
 1.	Display a welcome message and a title, such as “Working with random numbers and simple mathematical functions”. Then display the name of the library functions you are going to use in this program and the header files needed for each function.
 2.	Generate 3 random numbers between -5 and 13 inclusive:
     r1, r2, r3
 3.	Generate one random number between 2 and 6 inclusive, name it x
 4.	Calculate result as r3 to the power of x
 5.	Calculate the average of the 3 random numbers
 6.	Calculate the square root of the average
 7.	Calculate the geometric mean of the random numbers (the product of these numbers to the power of 1 / 3)
 8.	Display a line of “=”, such as “=================\n”
 9.	Display the following (with description):
 •	 r1, r2, r3
 •	 r3, x, and result
 •	average of the 3 numbers with 2 digits after the decimal point
 •	square root of the average with 4 digits after the decimal point
 •	geometric mean of the random numbers with 1 digit after the decimal point
 

Brian Le
Unix

*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int r1,
        r2,
        r3,
        x;

    double result,
           avg,
           square_root,
           product,
           geometric_mean;
    
    srand(time(0));
    r1 = rand()%(13 - - 5 + 1) - 5;
    r2 = rand()%(13 - - 5 + 1) - 5;
    r3 = rand()%(13 - - 5 + 1) - 5;
    x = rand()%(6 - 2 + 1) + 2;
    
    //calculations
    result = pow(r3, x);
    avg = (r1 + r2 + r3)/3.0;
    square_root = pow(avg, 0.5); //can also use sqrt()
    product = r1 * r2 * r3;
    geometric_mean = pow(product, (1.0/3));
                
    //output
    cout << "Mathematical functions using 3 randomly generated numbers\n";
    cout << "Header files and functions used:\n";
    cout << "iostream - cin, cout\n";
    cout << "cmath - pow()\n";
    cout << "cstdlib - rand(), srand()\n";
    cout << "ctime - time()\n";
    cout << "iomanip - setprecision(), fixed\n";
    cout << "=========================================================\n";
    
    cout << "Random numbers in (-5, 13) generated: "
         << r1 << ", " << r2 << ", " << r3 << endl;
    cout << "Random number in (2, 6) generated: " << x << endl;
    cout << r3 << " to the " << x << "th power is " 
         << result << endl;
    cout << "The average of " << r1 << ", " << r2 << ", and " << r3 << " is " 
         << setprecision(2) << fixed << avg << endl;
    cout << "The square root of " << avg << " is " << setprecision(4) 
         << fixed << square_root << endl;
    cout << "The geometric mean of " << r1 << ", " << r2 << ", and " << r3 << " is " 
         << setprecision(1) << fixed << geometric_mean << endl;
    
    return 0;
}
/*********************************************************************************
Mathematical functions using 3 randomly generated numbers
Header files and functions used:
iostream - cin, cout
cmath - pow()
cstdlib - rand(), srand()
ctime - time()
iomanip - setprecision(), fixed
=========================================================
Random numbers in (-5, 13) generated: 6, 3, 13
Random number in (2, 6) generated: 4
13 to the 4th power is 28561
The average of 6, 3, and 13 is 7.33
The square root of 7.33 is 2.7080
The geometric mean of 6, 3, and 13 is 6.2

*/


/*********************************************************************************
Mathematical functions using 3 randomly generated numbers
Header files and functions used:
iostream - cin, cout
cmath - pow()
cstdlib - rand(), srand()
ctime - time()
iomanip - setprecision(), fixed
=========================================================
Random numbers in (-5, 13) generated: 13, -1, -4
Random number in (2, 6) generated: 5
-4 to the 5th power is -1024
The average of 13, -1, and -4 is 2.67
The square root of 2.67 is 1.6330
The geometric mean of 13, -1, and -4 is 3.7

*/
