/**
   There are a number of syntax errors in the following program.
   Locate all errors, fix them, run the program and save its output.
 
   Brian Le
   Unix vim gcc
*/

/* What is wrong with this program? 
 -multi-line comment syntax incorrect
 -missing semicolons
 -c variable incorrectly capitalized
 -curly braces incorrect
 -no semicolon needed after #include <iostream>
 -// for single line comments, not \\
 -return 0, not return0
 */
#include <iostream>

using namespace std;

int main()
{
	int a, b, c; // three integers
                                     
    a = 3;
    b = 4;
    c = a + b;
                                     
    cout << a << " + " << b << " = " << c << endl;
    return 0;

}
                                     
/*********************************************************************************
3 + 4 = 7
 
*/
