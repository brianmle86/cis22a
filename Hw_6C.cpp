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
 
 NAME:
 
 *~**/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int DE_BUG = true;

void printInfo(void);
bool getScores(void);
void calcScore(void);
void findLowest(void);
void findHighest(void);
void writeScore(void);
void printEnd(void);

int main() {
    // declare the variables needed in main()
    ifstream inFile;
    ofstream outFile;

    printInfo();
    // open the input file + validation
    inFile.open("performers.txt");
    if (!inFile) {
        cout << "Could not open file.\n";
        return 1;
    }
    // open the output file + validation
    outFile.open("results.txt");
    if (!outFile) {
        cout << "Could not open file.\n";
        return 1;
    }

    while (getScores()) {
        calcScore();
        // determine the winner so far
        writeScore();
    }
    // close the input file
    inFile.close();
    // close the output file
    outFile.close();
    // display the number of participants
    // display the winner and the winner's score
    
    printEnd();
    return 0;
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void printInfo(void)
{
    if (DE_BUG)
        cout << "This is the welcome function" << endl;
    cout << "Welcome to the competition results calculator!\n"
         << "There are five judges who give out a score,\n"
         << "and the highest and lowest scores are dropped.\n"
         << "The final score is the average of the three remaining scores.\n";
}

/*~*~*~*
 This function reads the performer's name, followed by their 5 scores. It returns true
 if it succeeds, and false if it doesn't.
 */
bool getScores(ifstream &inFile, string &name, double &score1, double &score2
               double &score3, double &score4, double &score5)
{
    if (DE_BUG)
        cout << "This is the getScores function" << endl;
    
    return bool(inFile >> name >> score1 >> score2 >> score3 >>
                score4, score5);  // change this line (see 6B)
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void calcScore(void)
{
    if (DE_BUG)
        cout << "This is the calcScore function" << endl;
    findLowest();
    findHighest();
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void findLowest(void)
{
    if (DE_BUG)
        cout << "\tThis is the findLowest function" << endl;
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void findHighest(void)
{
    if (DE_BUG)
        cout << "\tThis is the findHighest function" << endl;
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void writeScore(void)
{
    if (DE_BUG)
        cout << "This is the writeScore function" << endl;
}

/*~*~*~*
 Write a comment here to describe the purporse of this function.
 
 */
void printEnd(void)
{
    if (DE_BUG)
        cout << "This is the END function" << endl;
}
