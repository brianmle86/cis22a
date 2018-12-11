/*
  Exam Statistics II
 
NAME: Brian Le
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Function prototypes
void print_info(void);
void read_file(ifstream &, int [], string [], int &, const int &, string &, int &);
double get_avg(int [], int);
int get_highest(int [], int);
int get_lowest(int [], int);
void display_results(string [], int [], int, int, int, double); 
void write_outfile(ofstream &, string, int [], string [], int); 
void sort_id(int [], string [], int);
void sort_score(int [], string [], int);
void done(void);

int main() {
    const int SIZE = 45;
    int score, num_students = 0,
        max, min;
    ifstream inFile;
    ofstream outFile1, outFile2;
    string id;
    string student_ids[SIZE];
    int exam_scores[SIZE];
    double avg;

    print_info();

    //read into parallel arrays
    read_file(inFile, exam_scores, student_ids, num_students, SIZE, id, score);
    
    //sort by id(ascending)
    sort_id(exam_scores, student_ids, num_students);
    write_outfile(outFile1, "scoresOut1.txt", exam_scores, student_ids, num_students);
    
    //sort by score(descending)
    sort_score(exam_scores, student_ids, num_students);
    write_outfile(outFile2, "scoresOut2.txt", exam_scores, student_ids, num_students);
    
    avg = get_avg(exam_scores, num_students);
    max = get_highest(exam_scores, num_students);
    min = get_lowest(exam_scores, num_students);
    
    display_results(student_ids, exam_scores, max, min, num_students, avg);

    done();
    return 0;
}



/**
 This function displays basic information about
 the program.
 */
void print_info() {
    cout << "This program reads scores.txt, which contains student IDs with their\n"
         << "respective test scores into two arrays, and displays:\n"
         << "-The total number of students\n"
         << "-The class average\n"
         << "-lowest score with that student's ID\n"
         << "-highest score with that student's ID\n"
         << "The output files scoresOut1.txt and scoresOut2.txt will be created.\n"
         << "scoresOut1.txt contains the arrays sorted in ascending order by id.\n"
         << "scoresOut2.txt contains the arrays sorted in descending order by score.\n\n";
}

/**
 This function takes an input file, two parallel arrays, number of students, max class size,
 id, and score as arguments. It reads the contents of the file into two parallel arrays.
 */
void read_file(ifstream &inFile, int exam_scores[], string student_ids[], int &num_students,
        const int &SIZE, string &id, int &score) {
    inFile.open("scores.txt");
    if (!inFile) {
        cout << "Could not open file.\n";
        exit(1);
    }
    while(num_students < SIZE && inFile >> id >> score) {
        student_ids[num_students] = id;
        exam_scores[num_students] = score;
        num_students++;
    }
    inFile.close();
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
    cout << endl << "Number of students: " << num_students << endl;
    cout << "Average score: " << avg << endl;
  
}

/**
 This function takes an output file, a filename, two parallel arrays, and
 the number of students as arguments. It writes the two arrays to an
 output file with the given filename.
 */
void write_outfile(ofstream &outFile, string filename, int exam_scores[],
        string student_ids[], int num_students) {
    outFile.open(filename);
    if (!outFile) {
        cout << "Could not open output file.\n";
        exit(1);
    }
    for(int i = 0; i < num_students; i++) {
        outFile << student_ids[i] << " "
                << exam_scores[i] << endl;
    }
    outFile.close();
}

/**
 This function takes two parallel arrays and the number of students
 as arguments. It sorts the arrays in ascending order by student id.
 */
void sort_score(int exam_scores[], string student_ids[], int num_students) {
    for(int i = 0; i < num_students; i++) {
        int min_index = i;
        for(int k = i + 1; k < num_students; k++) {
            if(exam_scores[k] > exam_scores[min_index])
                min_index = k;
        }
        int swap1 = exam_scores[min_index];
        exam_scores[min_index] = exam_scores[i];
        exam_scores[i] = swap1;
        
        string swap2 = student_ids[min_index];
        student_ids[min_index] = student_ids[i];
        student_ids[i] = swap2;
    }

}

/**
 This function takes two parallel arrays, and the number of students
 as arguments. It sorts the arrays in descending order by exam score.
 */
void sort_id(int exam_scores[], string student_ids[], int num_students) {
    for(int i = 0; i < num_students; i++) {
        int max_index = i;
        for(int k = i + 1; k < num_students; k++) {
            if(student_ids[k] < student_ids[max_index])
                max_index = k;
        }
        string swap1 = student_ids[max_index];
        student_ids[max_index] = student_ids[i];
        student_ids[i] = swap1;
        
        int swap2 = exam_scores[max_index];
        exam_scores[max_index] = exam_scores[i];
        exam_scores[i] = swap2;
    }
}


/**
 This function displays an end of
 program message.
 */
void done() {
    cout << endl << "This is the end of the program. Thanks for using it.\n";
}

/****
Output:
This program reads scores.txt, which contains student IDs with their
respective test scores into two arrays, and displays:
-The total number of students
-The class average
-lowest score with that student's ID
-highest score with that student's ID
The output files scoresOut1.txt and scoresOut2.txt will be created.
scoresOut1.txt contains the arrays sorted in ascending order by id.
scoresOut2.txt contains the arrays sorted in descending order by score.

Student IDs with the highest score of 100: 2ABCD AK323 DR123 
Student IDs with the lowest score of 45: 9QWE9 SW111 TY4XZ 
Number of students: 13
Average score: 81.6923

This is the end of the program. Thanks for using it.

*/


