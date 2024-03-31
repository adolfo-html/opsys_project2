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

// m = number of rows.
int m;
// n = number of columns.
int n;

// main has an argument you need to pass it. This argument is a string indicating the address of the
// file you want to scan.
int main(int argc, char* argv[])
{
    // Step 0: Interface & getting the digits

    // This step checks if you've passed an argument or not. If not, doesn't run the main program.
    // Also you need to have your program check if there are any arguments FIRST before you try to 
    // access the arguments. Otherwise, you'll end up with a segmentation fault if there are no arguments.
    
    if (argc == 1) // You running a.out counts as an argument. Huh!
    {
        // Interface
        cout << "Welcome to my second project.\n\n";
        cout << "Please pass your input file name as an argument to this program.\n";
        cout << "Your first line should be your m and n values for your matrices, where:\n";
        cout << "m = number of matrix rows\n";
        cout << "n = number of matrix columns\n\n";

        cout << "      \\    /\\\n       )  ( ')\n      (  /  )\n       \\(__)|\n\n"; // Art

        cout << "See ya!\n";
    } else {
// EVERYTHING BELOW HERE CONTAINS MAIN FUNCTION OPERATIONS AND INITIALIZERS

        string fileName = argv[1];

        // I forgor how to read content from a file :skull:

        string contentText;

        // The object in question:
        ifstream file(fileName);

        int lineCount = 0;
        while (getline(file, contentText))
        {
            // Holy crap this is cool.
            // Char values equal the number or letter's ASCII VALUE!
            // So if I wanted to change a char data type (in this case, the part of the string I need)
            // into an int, I would subtract the ASCII value of 0 from the ASCII value of the char,
            // and for 3 it's 51 and that's why the value of m when I set it equal to contentText[0]
            // was returning 51 earlier. But anyway, that's what makes it work.
            // That's how the char data type works. The character 'A' has an ASCII value of 65.
            // So if you wanted to, you could declare this character by saying char lettera = 64 + 1;.
            if (lineCount == 0)
            {
                m = contentText[0] - '0';
                n = contentText[2] - '0';
            }
            lineCount++;
        }

        // Erm it didn't let me declare this because I put it right next to int m, n; which makes
        // the value of m and n garbage data. 
        // Variables with indeterminate values are variables you define like how you did earlier
        // with the int m, n; line. You should study these, they're straightforward but cool. You
        // generally can't access other programs' data with these though, they literally just contain
        // random values, which goes back to the fact that this entire program is in its own block of memory

        // The m x n matrix that indicates the number of resources of each type currently allocated to each process.
        int allocation[m][n];

        // The m x n matrix that indicates the current request of each process.
        int request[m][n];

        // The VECTOR, of size n, that indicates the number of available resources of each type.
        int available[n];

        // I have to run this function again because the last one gave me the variables I need to be able
        // to use these variables.

        ifstream file2(fileName);

        // ASSIGN MATRIX VALUES
        int allocationLineCount = 0;
        int requestLineCount = 0;
        int availableLineCount = 0;
        while (getline(file2, contentText))
        {
            // This is the ONLY variable that needed to be checked was at m + 1. m + 1 is to make sure
            // the first line isn't counted, because we have to scan the file again, remember?
            if (allocationLineCount < m + 1)
            {
                // ASSIGN ALLOCATION MATRIX VALUES
                for(int i = 0; i < n; i++)
                {
                    allocation[allocationLineCount - 1][i] = contentText[0 + (2 * i)] - '0';
                }
                allocationLineCount++;
            }
            // Yeah, and each one of these else if conditions is checked SEQUENTIALLY. So if one is
            // true, it stops at what's under the true condition and runs that segment. Nothing else. Cool
            // And yeah that's what was stopping availableLineCount from being counted here. I was checking
            // requestLineCount < m + 1 when it should have just been m, because we're back on track.
            else if (requestLineCount < m)
            {
                // ASSIGN REQUEST MATRIX VALUES
                for(int i = 0; i < n; i++)
                {
                    request[requestLineCount][i] = contentText[0 + (2 * i)] - '0';
                }
                requestLineCount++;
            }
            else if (availableLineCount < m)
            {
                for(int i = 0; i < n; i++)
                {
                    available[i] = contentText[0 + (2 * i)] - '0';
                }
                availableLineCount++;
            }
        }
        
        // PRINT MATRICES
        // I'm lazy so here's TWO print matrix functions, copy and pasted. LOL
        // I can't figure out how to send an entire 2D array to a function, so here

        // PRINT ALLOCATION MATRIX
        cout << "The allocation matrix is: \n";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << allocation[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        // PRINT REQUEST MATRIX
        cout << "The request matrix is: \n";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << request[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        // PRINT AVAILABLE VECTOR
        cout << "The available vector is: \n";
        for (int i = 0; i < n; i++)
        {
            cout << available[i] << " ";
        }
        cout << "\n";
    }


    return 0;
}