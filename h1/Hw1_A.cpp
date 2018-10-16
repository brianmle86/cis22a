/**~*~*
   This is the first program that just writes out a simple message
 
   Brian Le
   vim + gcc
*/

#include <iostream>     // The Input/ Output stream header file is needed to perform C++ I/O

using namespace std;   // C++ uses namespaces to  organize the names in program entities
// In order for a program to use the entities in iostream, it must have access to the
// std (standard) namespace

// A C++ program consists of one or more functions. Every C++ program must have
int main ()           // a function called main: it is the starting point of the program.
{
    // fill in the blanks below
    cout << endl;
    cout << "    My name is Brian" << endl << endl;
    cout << "    I am taking 22A because I want to learn more about programming concepts" << endl;
    cout << "    My main goal is to apply my knowledge by writing programs" << endl << endl;
    cout << "===============================================" << endl;
    cout << "    Developing a program in a language such as C++ \n    requires at least four steps:" << endl;
    cout << "        1. edit (write)\n"
         << "        2. compile (translate in machine language)\n"
         << "        3. link\n"
         << "        4. run";
    cout << endl << endl;
    
    return 0;
}
/**~*~*

    My name is Brian

    I am taking 22A because I want to learn more about programming concepts
    My main goal is to apply my knowledge by writing programs

===============================================
    Developing a program in a language such as C++ 
    requires at least four steps:
        1. edit (write)
        2. compile (translate in machine language)
        3. link
        4. run

*/
