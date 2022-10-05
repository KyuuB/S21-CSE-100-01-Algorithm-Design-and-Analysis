// Source code from Geeksforgeeks 
// https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/
// Source code from textbook page 72 also used.
#include <iostream>
// Used to define the minimum integer
#include <limits.h>

using namespace std;

// Used to find max between 2 integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
// Used to find the max between 3 integers
int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

// Used to find the max between crossing arrays.
int maxCross(int A[], int low, int mid, int high)
{
    //Leftsum initialized to -infinity
    int leftsum = INT_MIN;
    //sum initialized
    int sum = 0;
    //For loop from mid to low
    for (int i = mid; i >= low; i--)
    {
        //Calculates sum from mid to mid - i until low one by one
        sum = sum + A[i];
        // Saves the max into left sum
        if (sum > leftsum) 
        {
            leftsum = sum;
        }
    }
    //Right sum initialized to -infinity
    int rsum = INT_MIN;
    //Sum set to 0
    sum = 0;
    //For loop from mid + 1 to high 
    for (int j = mid + 1; j <= high; j++) 
    {
        //Calculates sum from mid + 1 to mid + j until high
        sum = sum + A[j];
        // If max is found it is saved into right sum
        if (sum > rsum)
        {
            rsum = sum;
        }
    }
    // max is found between right sum, left sum,
    // and right sum + left sum
    return max(leftsum, rsum, leftsum + rsum);
}

// Recursively divides array until array has a size of 1
int maxSubarray(int A[], int low, int high) 
{
    //Recursion stops when high index is equal to low index
    if (high == low)
    {
        //Returns max of the array of size 1 which is 
        // just the value at A[low].
        return (A[low]);
    }
    //Splits the array into halves and calls the maxSubArray for 
    // each half, and calls the max Crossing SubArray.
    else
    {
        int mid = (low + high) / 2;
        // Returns the max from each call.
        return max(maxSubarray(A,low, mid),
        maxSubarray(A, mid + 1, high),
        maxCross(A, low, mid, high));
    }

}


int main() 
{
    //Initialize Pointer and array size
    int* Sequence;
    int arraySize = 1;

    //Grabs array size from user
    cin >> arraySize;
    //Initializes an array with size from user
    Sequence = new int[arraySize];

    //Populates array
    for(int i = 0; i < arraySize; i++)
    {
        cin >> Sequence[i];
    } 

    //Function calls to Max Subarray Problem
    int maximumSubArray = maxSubarray(Sequence, 0, arraySize - 1);
    printf("%d", maximumSubArray);
    return 0;
}