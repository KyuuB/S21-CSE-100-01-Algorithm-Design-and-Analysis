#include <iostream>
#include <cstdlib>

//Some source code from geeks for geeks.
//https://www.geeksforgeeks.org/quicksort-using-random-pivoting/

using namespace std;


int Partition(int A[], int p, int r) {

    //x will be the pivot
    int x = A[r];
    //i is the index before the first index
    int i = p - 1;

    //From p to r the indexes i and j will be switched based on the pivot.
    for (int j = p; j <= r - 1; j++){
        //If the index is smaller than the pivot then indexes i and j 
        // are switched
        if (A[j] <= x) {
            i++;

            swap(A[i], A[j]);
        }
    }
    //Once partitioned the pivot and index where i++ stopped will be switched
    swap(A[i + 1], A[r]);
    //Returns index after the switched pivot.
    return (i + 1);
}

int rPartition(int A[], int p, int r) {
    //i will be a random number between indexes p and r.
    int i = rand() % (r - p) + p;
    //swap the random pivot with the last index
    swap(A[i], A[r]);

    //Partition the newly random pivoted.
    return Partition(A, p, r);
}

//Continuously split the array using the random partition as the pivot.
int rQuicksort(int A[], int p, int r) {
    if (p < r) {
        //Grab random number from p to r.
        int q = rPartition(A, p ,r);
        //Separate quicksorts for the left and right of the pivot
        rQuicksort(A, p, q - 1);
        rQuicksort(A, q + 1, r);

    }
}

//Prints Array
void printArray(int A[], int index) {
    for (int i = 0; i < index; i++)
    {
        cout << A[i] << ";";
    }
    
}

int main() {
    //Initialize array
    int* array;
    int arraySize = 1;

    //User input for array size
    cin >> arraySize;

    //User inputs into array
    for (int  i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }

    //Function calls to the methods 
    rQuicksort(array, 0, arraySize - 1);
    printArray(array, arraySize);
    
    return 0;
}