#include <iostream>
#include <string>
#include <list>
#include <sstream>

using namespace std;

//Source code from https://www.geeksforgeeks.org/c-program-hashing-chaining/

//Class
class hashTable {
    //m or the number of linked lists
    int BUCKET;
    //linked list to a table pointer
    list<int> *table;
public:
    //Functions used
    hashTable(int m);

    void insertItem(int k);
    void deleteItem(int k);
    void searchHash(int k);
    void displayHash();

    int hashFunction(int x) {
        return (x % BUCKET);
    }
};

//Initialize hashTable with m
hashTable::hashTable(int m)
{   
    //Bucket is now of size m
    this->BUCKET = m;
    //table pointing to new linked list of int, of size m.
    table = new list<int>[BUCKET];
}

//Insert function 
void hashTable::insertItem(int k) {
    //index is hashFunction output from k input.
    int index = hashFunction(k);
    //Depeding on the hashFunction, the k is inserted into
    // different linked list with the push_front function from <list>
    table[index].push_front(k);
}

//Delete int
void hashTable::deleteItem(int k) {
    //index from h function
    int index = hashFunction(k);
    //New iterator to act as a i++ for linked lists in list
    list <int> :: iterator itr;
    //Using index, start from begining to end with itr++ increments
    for (itr = table[index].begin(); itr != table[index].end(); itr++) {
        //Once the k is found break the for loop
        if (*itr == k)
        break;
    }
    //If itr is not at the end of the linked list, then delete the int
    if (itr != table[index].end()) {
        table[index].erase(itr);
        cout << k << ":DELETED;" << endl;
    }
    //Else if itr is not at the end of the linked list, then the delete
    // was failed.
    else {
        cout << k << ":DELETE_FAILED;" << endl;
    }
}

//Prints the hash table chain
void hashTable::displayHash() {
    //from 0 to m, for the array connected to the linked lists
    for (int i = 0; i < BUCKET; i++) {
        //Display array index 
        cout << i << ":";
        //Iterator to act as counter 
        list <int> :: iterator itr;
        //From beginning to end print the number using itr dereference
        for (itr = table[i].begin(); itr != table[i].end(); itr++) {
            cout << *itr << "->";
        }
        cout << ";" << endl;
    }
}

//Search function 
void hashTable::searchHash(int k) {
    //index as output from k mod m
    int index = hashFunction(k);
    //counter used to display number of -> nexts performed to reach key
    int indexList = 0;
    //Iterator used to traverse list
    list <int> :: iterator itr;
    //Beginning to end of indexed linked list
    for (itr = table[index].begin(); itr != table[index].end(); itr++) {
        //count -> nexts 
        indexList++;
        //If key is found break for loop
        if (*itr == k)
        break;
    }
    //Adjust for extra jump in search
    indexList--;
    //If itr is not at the end of the linked list, print the location of
    // the k in hash table chain
    if (itr != table[index].end()) {
        cout << k << ":FOUND_AT" << index << "," << indexList << ";" << endl;
    }
    //If itr is at the end, the key was not found
    else {
        cout << k << ":NOT_FOUND;" << endl;
    }
     
}

//Switch cases for all the user inputs. 
void switchCase(char c, int n, hashTable hashTable) {
    switch ( c ) {
        case 'i' :
            hashTable.insertItem(n);
            break;
        case 's' :
            hashTable.searchHash(n);
            break;
        case 'd' :
            hashTable.deleteItem(n);
            break;
        case 'o' : 
            hashTable.displayHash();
            break;
        case 'e' : 
            break;
        default:
            cout << "Incorrect Case" << endl;
            break;
    }
}

int main() {
    
    //Initializing variables
    int m;
    int n;
    char c;
    string str;
    string str2;

    //user input for number of buckets
    cin >> m;

    //hashTable defined by m.
    hashTable hashTable(m);

    //User inputs until e
    while (c != 'e') {

    //User input into str
    cin >> str;
    
    //New string cuts out first char in string to get index
    str2 = str.substr(1, str.size());
    //stringstream for both to get the character and index
    istringstream(str) >> c;
    istringstream(str2) >> n;

    //Switch case based on userinput
    switchCase(c, n, hashTable);

    }

}