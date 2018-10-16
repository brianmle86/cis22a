/**~*~*~*
   PART B
 
   This program asks the user to enter a number, it performs some calculations,
   and displays the results.
   
   Brian Le
   text editor +terminal
*/
#include <iostream>

using namespace std;

int main()
{
    int number;
    int square;

    cout << "Hi there" << endl;
    cout << "Please input a number and then hit return" << endl;
    cin  >> number;

    square = number * number;
    
    cout << "The square of " << number << " is " << square << endl;
    return 0;
}
/**~*~*~*~*~*~*~*~*~**

Hi there
Please input a number and then hit return
19
The square of 19 is 361

Hi there
Please input a number and then hit return
not a number
The square of 0 is 0
*/
