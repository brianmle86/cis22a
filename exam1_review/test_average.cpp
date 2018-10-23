//created by Brian Le 10/18/18

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double test_score1,
           test_score2,
           test_score3,
           test_score4,
           test_score5,
           avg; 
    cout << "Enter 5 test scores: ";
    cin >> test_score1 >> test_score2 >> test_score3 >> test_score4 >> test_score5;

    //calculation
    avg = (test_score1 + test_score2 + test_score3 + test_score4 + test_score5)/5;

    //output
    cout << "The average test score is: " << setprecision(1) << fixed << avg << endl;

}
