
//created by Brian Le 10/18/18
#include <iostream>

using namespace std;

int main() {
    double miles,
           gallons,
           mpg,
           distance,
           price;
    
    cout << "How many gallons can your car hold? ";
    cin >> gallons;

    cout << "How many miles can be driven on a full tank? ";
    cin >> miles;

    //calculations
    mpg = miles/gallons;

    //output
    cout << "MPG: " << mpg << endl;

}
    
    

