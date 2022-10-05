#include <iostream>

using namespace std;

// Source code courtesy of Geeks for geeks
// https://www.geeksforgeeks.org/heap-sort/

void heapify(int A[], int index, int i) {
    //New int to find max in array
    int max = i;
    //Creates left and right node 
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    //Finds the max between the left and right nodes
    if (l < index && A[l] > A[max]) {
        max = l;
    }
    if (r < index && A[r] > A[max] ) {
        max = r;
    }
    //If the max has changed from i.
    //Swap max and i in the array
    if (max != i) {
        swap(A[i], A[max]);
        //Recursive call unless max is unchanged 
        heapify(A, index, max);
    }
}

void heapSort(int A[], int index) {

    //Call heapify at the half index to 0
    for (int i = index / 2 - 1; i >= 0; i--) {
        heapify(A, index, i);
    }
    //Call heapify at index to 0
    for (int i = index - 1; i > 0; i--) {
        //Swaps first index for i
        swap (A[0], A[i]);
        //Heapify from index to 0
        heapify(A, i, 0);
    }
}
//Prints array
void printArray(int A[], int index) {
    for (int i = 0; i < index; i++)
    {
        cout << A[i] << ";";
    }
    
}
int main() {
    //Initialize pointer and array size
    int* Sequence;
    int arraySize = 1;

    //arraySize from user
    cin >> arraySize;

    //Populates array
    for (int i = 0; i < arraySize; i++)
    {
        cin >> Sequence[i];
    }
    
    //Function calls
    heapSort(Sequence, arraySize);
    printArray(Sequence, arraySize);

    return 0;
}