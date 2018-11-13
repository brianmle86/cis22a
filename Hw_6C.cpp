/**~*~*~*~*~*
 Project 6C: Performers
 
 A particular talent competition has five judges, each of whom awards a score between
 0 and 10 to each performer. Fractional scores, such as 8.3, are allowed.
 A performer's final score is determined by dropping the highest and the lowest score
 received, then averaging the three remaining scores. Write a program that calculates
 the score of each performer and determines the winner.
 Assume there's only one winner!
 
 Input: Read data from an input file named performers.txt.
 Output: Write the number of participants, the name of the winner and winner’s score to
 the screen. Write to a file named results.txt the names of the performers and their
 final score.
 
 NAME: Brian Le
 
 *~**/

#include <iostream>
#include <fstream>

using namespace std;

const int DE_BUG = false;

void printInfo(void);
bool getScores(ifstream &, string &, double &, double &,
               double &, double &, double &);
double calcScore(double, double, double, double,
               double);
double findLowest(double, double, double, double,
                double);
double findHighest(double, double, double, double,
                double);
void writeScore(ofstream &, string, double);
void printEnd(void);

int main() {
    // declare the variables needed in main()
    ifstream inFile;
    ofstream outFile;
    string name, winner;
    double score1, score2, score3, score4, score5;
    double finalScore,
           winnerScore = 0;
    double numPeople = 0;


    printInfo();
    // open the input file + validation
    inFile.open("performers.txt");
    if (!inFile) {
        cout << "Could not open input file.\n";
        return 1;
    }
    // open the output file + validation
    outFile.open("results.txt");
    if (!outFile) {
        cout << "Could not open output file.\n";
        return 1;
    }

    while (getScores(inFile, name, score1, score2, score3, score4, score5)) {
        numPeople++;
        finalScore = calcScore(score1, score2, score3, score4, score5);
        // determine the winner so far
        if (finalScore > winnerScore) {
            winnerScore = finalScore;
            winner = name;
        }
        writeScore(outFile, name, finalScore);
    }
    // close the input file
    inFile.close();
    // close the output file
    outFile.close();
    // display the number of participants
    cout << "Number of participants: " << numPeople << endl;
    // display the winner and the winner's score
    cout << "The winner is " << winner << " with a score of "
         << winnerScore << endl;
    printEnd();
    return 0;
}

/*~*~*~*
  This function takes no arguments and displays basic
  information about the program.
  */
void printInfo(void) {
    if (DE_BUG)
        cout << "This is the welcome function" << endl;
    cout << "Welcome to the competition results calculator!\n"
         << "There are five judges who give out a score,\n"
         << "and the highest and lowest scores are dropped.\n"
         << "The final score is the average of the three remaining scores.\n\n";
}

/*~*~*~*
 This function reads the performer's name, followed by their 5 scores. It returns true
 if it succeeds, and false if it doesn't.
 */
bool getScores(ifstream &inFile, string &name, double &score1, double &score2,
               double &score3, double &score4, double &score5) {
    if (DE_BUG)
        cout << "This is the getScores function" << endl;
    return bool(inFile >> name >> score1 >> score2 >> score3 >>
                score4 >> score5);  // change this line (see 6B)
}

/*~*~*~*
  This function takes 5 scores as arguments, and calls on findLowest() and findHighest()
  to calculate the final score of the performer. (middle 3 scores)
  */
double calcScore(double score1, double score2, double score3, double score4,
               double score5) {
    if (DE_BUG)
        cout << "This is the calcScore function" << endl;
    
    double max, min, totalScore, finalScore;
    totalScore = score1 + score2 + score3 + score4 + score5;
    min = findLowest(score1, score2, score3, score4, score5);
    max = findHighest(score1, score2, score3, score4, score5);
    finalScore = totalScore - max - min;
    return finalScore;
}
/*~*~*~*
  This function takes 5 scores as arguments and calculates the minimum
  of the 5 scores and returns that value.
  */
double findLowest(double score1, double score2, double score3, double score4,
                double score5) {
    if (DE_BUG)
        cout << "\tThis is the findLowest function" << endl;
    
    double min;
    min = score1;
    if (min > score2)
        min = score2;
    if (min > score3)
        min = score3;
    if (min > score4)
        min = score4;
    if (min > score5)
        min = score5;
    return min;

}

/*~*~*~*
 This function takes 5 scores and calculates the maximum
 of the 5 scores and returns that value.
 */
double findHighest(double score1, double score2, double score3, double score4,
                double score5) {
    if (DE_BUG)
        cout << "\tThis is the findHighest function" << endl;
    
    double max;
    max = score1;
    if (max < score2)
        max = score2;
    if (max < score3)
        max = score3;
    if (max < score4)
        max = score4;
    if (max < score5)
        max = score5;
    return max;
}

/*~*~*~*
  This function takes the output file, name, and the final score as arguments, and
  writes the name of the performer and their final score in results.txt
  */
void writeScore(ofstream &outFile, string name, double finalScore) {
    if (DE_BUG)
        cout << "This is the writeScore function" << endl;
    outFile << name << " " << finalScore << endl;
}

/*~*~*~*
  This function takes no arguments and displays a farewell
  message at the end of the program.
  */
void printEnd(void) {
    if (DE_BUG)
        cout << "This is the END function" << endl;
    cout << endl << "This is the end of the program. Thanks!\n";
}
