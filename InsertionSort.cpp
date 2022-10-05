#include <iostream>

// #define MAX_INT 2147483647

using namespace std;

// Source code for Insertion Sort used from GeeksforGeeks:
// https://www.geeksforgeeks.org/insertion-sort/

// Method takes in an array and the size of the array,
// returns sorted array.
void insertionSort(int arr[], int n) 
{
    //Initialize
    int i, key, j;

    //Starting from index 1 cause index 0 is already sorted
    for (i = 1; i < n; i++)
    {

      //Grabbing the index
      key = arr[i];
      //Used to compare the index prior
      j = i - 1;

      //While loop that keeps going until the beginning
      //of the array is reached or if the index grabbed is 
      //larger than the index compared to going down the array
      while (j >= 0 && arr[j] > key)
      {

        //Moves the number in the index to the right
        arr[j + 1] = arr[j];

        //j is decremented to now check the next 
        //pointer lower in the array
        j = j - 1;
      }
      
      //Once the array is at the beginning or if arr[j] is larger 
      //than the key. the 
      arr[j + 1] = key;
    }
}

//Method to print an array using the array pointer, 
//and a specified index
void printArray(int arr[], int n)
{

  int i;
  //for loop starting at 0 and ending at specified index
  for (i = 0; i < n; i++)
  {
    //outputs the ith index followed by a semicolon
    cout << arr[i] << ";";
    
  }
}  
  
// int argc,char **argv
int main() {

  //intialization
  int* Sequence;
  int arraySize = 1;

  // Get the size of an Array
  cout << "Enter the size of the array: ";
  cin >> arraySize;
  Sequence = new int[arraySize];
    
  // Read the inputs and place into array.
  for(int i=0; i<arraySize; i++)
  {
    cout << "Input " << i + 1 << ": ";
    cin >> Sequence[i];
  }

  //Using the 2 <= k <= n to sort and print the array, 
  // starting from 2 since array is already sorted with a single int
  // 
  for(int i = 2; i <= arraySize; i++)
  {
    //Sorts then prints array from 0 to the ith index
    insertionSort(Sequence, i);
    printArray(Sequence, i);
    cout << endl;
  }

  // Free allocated space
  delete[] Sequence;

}
