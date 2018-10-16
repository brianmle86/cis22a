/**~*~*
   This program asks the user to enter a number, it performs some calculations,
   and displays the results. Run the program twice. First enter an even number,
   then enter an odd number. What do you notice? Write your answer below.
 
   Brian Le
   vim + gcc
*/
#include <iostream>

using namespace std;

int main()
{
    int number;
    int half_i, twice;
    double half_d;

    cout << "Hi there" << endl;
    cout << "Please input a number and then hit return" << endl;
    cin  >> number;

    twice = number * 2;
    half_i = number / 2;
    half_d = number / 2.0;
 
    cout << "Double of your number is " << twice << endl;
    cout << "Half of your number is " << half_i << endl;
    cout << "Half of your number is " << half_d << endl;
   
    return 0;
}
/**~*~*
Hi there
Please input a number and then hit return
10
Double of your number is 20
Half of your number is 5
Half of your number is 5


Hi there
Please input a number and then hit return
1
Double of your number is 2
Half of your number is 0
Half of your number is 0.5


Hi there
Please input a number and then hit return
not a number
Double of your number is 0
Half of your number is 0
Half of your number is 0

 
ANSWER: When you enter an odd number, half_i returns an integer, and half_d returns a double.
So when I input 1, the output was 0 and 0.5, 0 being an integer, and 0.5 being a double.
 
*/
