/**~*~*~*
   PART A

 Project: Calculate average of even numbers, sum of the odd numbers,
 and number of the negative numbers.

 Rewrite this program using proper indentation and spacing.

 Run the program three times and save each output as a comment at the end
 of the source file.

Brian Le
Unix

*/
#include <iostream>

using namespace std;

int main() {
    int n1,n2,n3;
    double eAvg;
    int eSum, oSum;
    int eCnt, oCnt, nCnt;
    
    cout<<"Enter three integers: ";
    cin >> n1 >> n2 >> n3;
    eSum = oSum = 0;
    eCnt = oCnt = nCnt = 0;
    
    if (n1 % 2 == 0) {
        eSum += n1;eCnt++;
    }
    else {
        oSum += n1;oCnt++;
    }
    if (n1 < 0)
        nCnt++;
    if (n2 % 2 == 0) {
        eSum += n2;eCnt++;
    }
    else {
        oSum += n2;oCnt++;
    }
    if (n2 < 0)
        nCnt++;
    if (n3 % 2 == 0) { 
        eSum += n3;
        eCnt++;
    }
    else {
        oSum += n3;oCnt++;
    }
    if (n3 < 0)
        nCnt++;
    if (eCnt > 0)
        eAvg = (double)eSum / eCnt;
    cout << "n1 = " << n1 << endl << "n2 = " << n2 << endl << "n3 = " << n3 << endl; 
    (eCnt > 0) ? 
        cout << "The average of the even numbers is " << eAvg << endl : cout << "There are no even numbers.\n";
    (oCnt > 0) ? 
        cout << "The sum of the odd numbers is " << oSum << endl : 
        cout << "There are no odd numbers.\n";
    (nCnt > 0) ? 
        cout << "There are/is " << nCnt <<  " negative number[s]\n" : 
        cout << "There are no negative numbers.\n";
    return 0;
}

/**~*~*~*~*~*~*~*~*~*~*~*~
Enter three integers: 6 4 2
n1 = 6
n2 = 4
n3 = 2
The average of the even numbers is 4
There are no odd numbers.
There are no negative numbers.
*/

/**~*~*~*~*~*~*~*~*~*~*~*~
Enter three integers: 8 5 2
n1 = 8
n2 = 5
n3 = 2
The average of the even numbers is 5
The sum of the odd numbers is 5
There are no negative numbers.
*/

/**~*~*~*~*~*~*~*~*~*~*~*~
Enter three integers: 7 -8 0
n1 = 7
n2 = -8
n3 = 0
The average of the even numbers is -4
The sum of the odd numbers is 7
There are/is 1 negative number[s]

*/
