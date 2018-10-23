/**~*~*~*
   PART B

 Project: Guess a number within a given range.

 Find and fix the errors.
 Run the program twice and save each output as a comment at the end
 of the source file.

 The program generates a random number within the range 1 to 8 (inclusive)
 and asks the user to guess it in one or two tries.

Brian Le
Unix

*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN = 1;
const int MAX = 8;
int main() {
    int random_num;
    int num;

    srand(time(0));
    random_num = rand() % 10 + 1;
    cout << "Enter a number within the range 1 to 8: ";
    cin >> num; // first try
    
    if ( (num>MAX) or (num<MIN) ) {
        cout << "Please enter a number within the range 1 to 8: ";
        return main();
    }

    if( num = random_num )
        cout << "Congratulations! You did it!\n\n";
    else {
        if( num < random_num )
            cout << "Your guess is low!";
        else {
            cout << "Your guess is high!";
        cout << " Try again!\n\n";
        cout << "Enter a number within the range 1 to 8: ";
        cin >> num; // second try
        }
        if ( num = random_num )
            cout << "Congratulations! You did it!\n\n";
        else
            cout << "Sorry, the number was %d\n\n", random_num;
    }
    return 0;
}

/**~*~*~*~*~*~*~*~*~*
SAVE THE FIRST OUTPUT HERE // <==== try to guess it!

*/


/**~*~*~*~*~*~*~*~*~*
SAVE THE SECOND OUTPUT HERE // <=== not guessed!

*/
