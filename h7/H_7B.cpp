/*
  Exam Statistics.
 
NAME: Brian Le
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Function prototypes
void print_info(void);
bool get_scores(ifstream &, string &, int &);
void get_arrays(string [], int [], ifstream &, string &, int &);
double get_avg(int [], int);
int get_highest(int [], int);
int get_lowest(int [], int);
void display_results(string [], int [], int, int, int, double); 
void write_outfile(ofstream &, string [], int [], int, double); 
void farewell(void);

int main() {
    const int SIZE = 45;
    int size, score, num_students = 0, max, min;
    ifstream inFile;
    ofstream outFile;
    string id, filename;
    string student_ids[SIZE];
    int exam_scores[SIZE];
    double avg;

    print_info();

    inFile.open("scores.txt");
    if (!inFile) {
        cout << "Could not open file.\n";
        return 1;
    }
    while(get_scores(inFile, id, score)) {
        num_students++;
        get_arrays(student_ids, exam_scores, inFile, id, score);
    }
    inFile.close();
    avg = get_avg(exam_scores, num_students);
    max = get_highest(exam_scores, num_students);
    min = get_lowest(exam_scores, num_students);
    display_results(student_ids, exam_scores, max, min, num_students, avg);   
    
    cout << "\nPlease enter a file name for the output file: ";
    cin >> filename;
    outFile.open(filename);
    if (!outFile) {
        cout << "Could not open file.\n";
        return 1;
    }
    write_outfile(outFile, student_ids, exam_scores, num_students, avg);
    outFile.close();
    farewell();
    return 0;
}
/**
 This function displays basic information about
 the program.
 */
void print_info() {
    cout << "This program reads scores.txt, which contains student IDs with their\n"
         << "respective test scores, sorts them into two arrays, and displays:\n"
         << "-The total number of students\n"
         << "-The class average\n"
         << "-lowest score with that student's ID\n"
         << "-highest score with that student's ID\n"
         << "The student IDs of those who scored less than the average will\n"
         << "be stored in an output file with a user-specified name.\n\n";
}

/**
 This function returns true while it can read a string
 and an integer from a file, and returns false otherwise.
 */
bool get_scores(ifstream &inFile, string &id, int &score) {
    return bool(inFile >> id >> score);
}

/**
 This function takes two arrays, an input file, id,
 and score as arguments. The fuction stores the id and score
 in the first indexes of the two arrays, and every time the
 function is called, it stores the next ids and scores in the
 following indexes. The result is two parallel arrays with
 corresponding student IDs and scores.
 */
void get_arrays(string student_ids[], int exam_scores[],
                ifstream &inFile, string &id, int &score) {
    static int i = 0;
    student_ids[i] = id;
    exam_scores[i] = score;
    i++;
}
/**
 This function takes an array of scores and the number
 of students as arguments. It returns the average score.
 */ 
double get_avg(int exam_scores[], int num_students) {
    double total = 0, avg;
    for(int i = 0; i < num_students; i++) {
        total += exam_scores[i];
    }
    avg = total / num_students;
    return avg;
}
/**
 This function takes an array of scores and the number
 of students as arguments. It returns the maximum score.
 */
int get_highest(int exam_scores[], int num_students) {
    int max;
    max = exam_scores[0];
    for(int i = 0; i < (num_students - 1); i++) {
        if (max < exam_scores[i+1])
        max = exam_scores[i+1];
    }
    return max;
}
/**
 This function takes an array of scores and the number
 of students as arguments. It returns the minimum score.
 */
int get_lowest(int exam_scores[], int num_students) {
    int min;
    min = exam_scores[0];
    for(int i = 0; i < (num_students - 1); i++) {
        if (min > exam_scores[i+1])
            min = exam_scores[i+1];
    }
    return min;
}
/**
 This function takes two parallel arrays, maximum score,
 minimum score, number of students, and average as arguments.
 It displays the number of students, average score, as well
 as the student IDs with the highest and lowest score.
 */
void display_results(string student_ids[], int exam_scores[], int max,
                     int min, int num_students, double avg) {
    cout << "Number of students: " << num_students << endl;
    cout << "Average score: " << avg << endl;
    int i = 0;
    cout << "Student IDs with the highest score of "
         << max << ": ";
    for(; i < num_students; i++) {
        if (max == exam_scores[i])
            cout << student_ids[i] << " ";
    }
    cout << endl;
    
    i = 0;
    cout << "Student IDs with the lowest score of "
         << min << ": ";
   for(; i < num_students; i++) {
        if (min == exam_scores[i])
            cout << student_ids[i] << " ";
    }
    cout << endl;
}
/**
 This function takes an output file, two parallel arrays,
 the number of students, and the average score as arguments.
 It writes student ID and the respective score if the score was
 less than the average.
 */
void write_outfile(ofstream &outFile, string student_ids[], int exam_scores[],
                 int num_students, double avg) {
    outFile << "Student IDs(and respective scores) with a score\n" 
            << "lower than the average of " << avg << ":\n";
    for(int i = 0; i < num_students; i++) {
        if (avg > exam_scores[i])
            outFile << student_ids[i] << " " << exam_scores[i] << endl;
    }
}
/**
 This function displays an end of
 program message.
 */
void farewell() {
    cout << "This is the end of the program. Thanks for using it.\n";
}

/****
Output:
This program reads scores.txt, which contains student IDs with their
respective test scores, sorts them into two arrays, and displays:
-The total number of students
-The class average
-lowest score with that student's ID
-highest score with that student's ID
The student IDs of those who scored less than the average will
be stored in an output file with a user-specified name.

Number of students: 13
Average score: 81.6923
Student IDs with the highest score of 100: DR123 2ABCD AK323 
Student IDs with the lowest score of 45: SW111 TY4XZ 9QWE9 

Please enter a file name for the output file: output.txt
This is the end of the program. Thanks for using it.
*/


