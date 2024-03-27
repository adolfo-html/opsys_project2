#include <iostream>
#include <fstream>
using namespace std;

// Step 1: Data Structures. There are 3: Available, Allocation, and Request.
// Available: This is a VECTOR of size m (a row of the matrix) that indicates the number of resources available for a specific resource type.
// Allocation: This is an m x n matrix that indicates the number of resources of each type that are CURRENTLY allocated to each process.
// Request: This is another m x n matrix that indicates the current REQUEST of each process.
// Work: A VECTOR of size m. (A row of the matrix)
// Finish: A VECTOR of size n. (Distinct from Work! This is a COLUMN of the matrix)

// I should probably also make some global variables, like m and n, which are the dimensions of the input matrix.
// I will keep the content of the file being scanned as a variable in main. Doesn't need to be global, because I can just scan the relevant info to other variables.

int m, n = 0;


// main has an argument you need to pass it. This argument is a string indicating the address of the
// file you want to scan.
int main(string fileName)
{
    // Step 0: Interface

    // This step checks if you've passed an argument or not. If not, doesn't run the main program.
    if (fileName == "")
    {
        cout << "Welcome to my second project.\n\n";
        cout << "Please pass your input file name as an argument to this program.\n";
        cout << "See ya!\n";
    } else {
        // I forgor how to read content from a file :skull:

        // STEPS to reading the content of a file:
        // 1. Create a stream object.
        // 2. Connect it to a file on disk. (probably the fstream function)
        // 3. Read the file's contents into our stream object. (We need a string function declared beforehand for this)
        // 4. Close the file. 

        string contentText;

        // The object in question:
        ifstream file(fileName);

        while (getline(file, contentText))
        {
            cout << contentText;
        }
    }

    return 0;
}