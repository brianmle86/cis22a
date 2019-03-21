#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 25;






void sortArray(int Tests[], int Size)
{
    int i, j, temp;
    for(int i = 0; i < (Size - 1); i++)
        {
            for (j = 0; j < Size-i-1; j++){  // Last i elements are already in place


           if (Tests[j] > Tests[j+1])
           {
                temp = Tests[j];
                Tests[j] = Tests[j + 1];
                Tests[j + 1] = temp;
            }
        }
        }

}

int main()
{
    int num1, n, Size = 0;
    int numbers[MAX];
    int i = 0;

    cout << "Enter an integer to search for " << endl;
    cin >> num1;

    ifstream inFile;
    inFile.open("nums-1.txt");          // Open file

    if(!inFile) { // Check File Error
        cout << "Could not open file " << endl;
        return 0;
    }

    while(inFile >> n) {
        numbers[i] = n;
        Size++;
        i++;
    }
    inFile.close();                     // Close file

    cout << "This array has " << Size << " items." << endl;

    int Tests[Size];
    inFile.open("nums-1.txt");          // Open file

    sortArray(numbers, Size);
    for(int i = 0; i < Size; i++) {
        cout << numbers[i] << endl;
    }
    inFile.close();

    return 0;
}
