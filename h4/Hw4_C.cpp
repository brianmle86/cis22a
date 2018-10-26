/**~*~*~*
   PART C
 
 Mobile Service Provider (Chapter 4, Project 25):
 
 Run the program 7 times using the following input:
 1.  A 400
 2.  A 700
 3.  B 825
 4.  B 1001
 5.  C
 6.  A -129 // error
 7.  D  // error!
 
 Display clear error messages, showing what was wrong.
 NOTE: Do not forget to define and use named constants.

Brian Le
Unix
*/

#include <iostream>

using namespace std;

const double PACK_A = 39.99;
const double PACK_B = 59.99;
const double PACK_C = 69.99;
const double RATIO_ADDITIONAL_A = 0.45;
const double RATIO_ADDITIONAL_B = 0.4;

int main() {
    char package;
    double minutes,
           additional_mins_cost,
           package_cost,
           total;

    cout << "Package A, B, or C? ";
    cin >> package;
    
    while (!(package == 'A' || package == 'B' || package == 'C')) {
        cout << "Try again. Package A, B, or C? ";
        cin >> package;
    }
    
    cout << "How many minutes were used? ";
    cin >> minutes;
    
    while (minutes < 0) {
        cout << "Minutes cannot be negative. How many minutes were used? ";
        cin >> minutes;
    }

    switch (package) {
        case 'A': package_cost = PACK_A;
                  if (minutes > 450)
                      additional_mins_cost = RATIO_ADDITIONAL_A * (minutes - 450);
                  else
                      additional_mins_cost = 0;
                  break;
        case 'B': package_cost = PACK_B;
                  if (minutes > 900)
                      additional_mins_cost = RATIO_ADDITIONAL_B * (minutes - 900);
                  else
                      additional_mins_cost = 0;
                  break;
        case 'C': package_cost = PACK_C;
                  additional_mins_cost = 0; //unlimited minutes
                  break;
        }
    
    //calculations
    total = package_cost + additional_mins_cost; 
    cout << "\nTotal amount due: $" << total << endl;
    
    return 0;
}
/**~*~*~*~*~*~*~*~*~*
Package A, B, or C? A
How many minutes were used? 400

Total amount due: $39.99

 */

/**~*~*~*~*~*~*~*~*~*
Package A, B, or C? A
How many minutes were used? 700

Total amount due: $152.49
 
 */

/**~*~*~*~*~*~*~*~*~*
Package A, B, or C? B
How many minutes were used? 825

Total amount due: $59.99
 
 */

/**~*~*~*~*~*~*~*~*~*
Package A, B, or C? B
How many minutes were used? 1001

Total amount due: $100.39
 
 */

/**~*~*~*~*~*~*~*~*~*
Package A, B, or C? C
How many minutes were used? //hangs forever, no input
 
 */

/**~*~*~*~*~*~*~*~*~*
Package A, B, or C? A      //minutes cannot be negative
How many minutes were used? -129
Minutes cannot be negative. How many minutes were used? -129
Minutes cannot be negative. How many minutes were used? -129
Minutes cannot be negative. How many minutes were used? //loop
 */

/**~*~*~*~*~*~*~*~*~*
Package A, B, or C? D
Try again. Package A, B, or C? D  //D not accepted as input
Try again. Package A, B, or C? D
Try again. Package A, B, or C? D
Try again. Package A, B, or C? //loop
 
 */
