#include <iostream>

using namespace std;

//Source for Merge Sort 
//https://www.geeksforgeeks.org/merge-sort/

//merge will bring the arrays together in order
void merge(int array[], int p, int q, int r) 
{   
    //Initializes first and second half of arrays
    const int n1 = q - p + 1;
    const int n2 = r - q;
    int L[n1], R[n2];

    //Copies half of each array into two separate arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = array[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = array[q + j + 1];
    }

    //Initialize indexes of each array
    int i = 0;
    int j = 0;
    int k = p;   

    //Here the while loop will grab the smallest earliest number
    // in each array. Once the smallest is grabbed it is placed 
    // back into the array[] in order.
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    
    //If there are leftovers from each half they will be added onto
    // the organized array.
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// mergeSort will recursively break down the array into halves
void mergeSort(int array[], int l, int r) {
    if (l >= r) {
        return;
    } 
    //Grabs middle of array
    int m = l + (r-l) / 2;
    //Calls left half
    mergeSort(array, l, m);
    //Calls right half
    mergeSort(array, m + 1, r);
    merge(array, l, m, r);

}

//prints array when called using the array and printing 0 to index.
void printArray(int array[], int index)
{
    for (int i = 0; i < index; i++)
    {
        cout << array[i] << ";";
    }
}

int main()
{
    //Initialize Pointer and array size
    int* Sequence;
    int arraySize = 1;

    //Grabs array size from user
    cout << "Enter the size of the array: ";
    cin >> arraySize;
    //Initializes an array with size from user
    Sequence = new int[arraySize];

    //Populates array
    for(int i=0; i<arraySize; i++)
    {
        cout << "Input " << i + 1 << ": ";
        cin >> Sequence[i];
    }   
    
    //Call functinos to mergesort and print the array.
    mergeSort(Sequence, 0, arraySize - 1);
    printArray(Sequence, arraySize);
    
    
    return 0;
    
}