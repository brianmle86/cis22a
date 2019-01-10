// This program uses the SELECTION sort algorithm to sort an
// array in ascending order.
#include <iostream>
using namespace std;

// Function prototypes
void selectionSort(int [], int);
void showArray(int [], int);

int main()
{
   // Define an array with unsorted values
   const int SIZE = 6;
   int values[SIZE] = {50, 70, 20, 80, 90, 10};

   // Display the values.
   cout << "The unsorted values are\n";
   showArray(values, SIZE);

   // Sort the values.
   selectionSort(values, SIZE);

   // Display the values again.
   cout << "The sorted values are\n";
   showArray(values, SIZE);
   return 0;
}

//**************************************************************
// Definition of function selectionSort.                       *
// This function performs an ascending order selection sort on *
// array. size is the number of elements in the array.         *
//**************************************************************

void selectionSort(int array[], int size)
{
   int startScan, minIndex, hold;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      // find index of the smallest value
      minIndex = startScan;
      for(int index = startScan + 1; index < size; index++)
      {
         if (array[index] < array[minIndex])
         {
            minIndex = index;
         }
      }
      // swap
      hold = array[minIndex];
      array[minIndex] = array[startScan];
      array[startScan] = hold;
   }
}

//**************************************************************
// Definition of function showArray.                           *
// This function displays the contents of array. size is the   *
// number of elements.                                         *
//**************************************************************

void showArray(int array[], int size)
{
   for (int count = 0; count < size; count++)
      cout << array[count] << " ";
   cout << endl;
}
