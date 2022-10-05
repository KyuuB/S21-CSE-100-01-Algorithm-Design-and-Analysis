#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int* rBottom_Up_Cut_Rod(int p[], int n) {
    //Created two different return pointers cause I was lazy
    //Initialize r with n+1 length
    int *r;
    r = new int[n+1];
    r[0] = 0;
    int q;
    //1 to n
    for (int j = 1; j <= n; j++)
    {   
        //q set to lowest amount
        q = INT_MIN;
        //0 to j 
        for (int i = 0; i < j; i++)
        {      
            //q becomes the max between the two
            q = max(q, p[i] + r[j - i - 1]);
        }
        //After the nested loop finishes, r[j] is set to the largest
        //q found
        r[j] = q;
    }
    //Return r pointer
    return r;
}

//Returns the s pointer
int* sBottom_Up_Cut_Rod(int p[], int n) {
    //Initializing
    int *r;
    r = new int[n+1];
    r[0] = 0;
    int q;
    int *s;
    s = new int[n+1];
    for (int j = 1; j <= n; j++)
    {
        q = INT_MIN;
        for (int i = 0; i < j; i++)
        {   
            //When q is changed to the max
            // the i + 1 is saved into the jth index
            if (q < (p[i] + r[j - i - 1])) {
                q = p[i] + r[j - i - 1]; 
                s[j] = i + 1;
            }
        }
        r[j] = q;
    }
    return s;
}

//Prints everything 
void printCut(int p[], int n) {
    int *r;
    int* s;
    //Calls for each returned pointer
    r = rBottom_Up_Cut_Rod(p, n);
    s = sBottom_Up_Cut_Rod(p, n);
    cout << r[n] << endl;

    //Prints the s[n] when n > 0,
    while (n > 0) {
        cout << s[n] << " ";
        n = n - s[n];
    }
    
    cout << -1 << endl;
}

int main() {
    //Initializing
    int n;
    int *p;
    int *result;
    int *cutSize;

    //User input for n
    cin >> n;

    p = new int[n];
    
    //User input for price array
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    //Print call
    printCut(p, n);

    return 0;
}