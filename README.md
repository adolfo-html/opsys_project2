# Operating Systems Project 2

Hi, this is my second OpSys project. I'm kind of rushing it.
The function is to scan an input file for 4 things: Dimensions m and n of a matrix, an m x n matrix, another m x n matrix, and a vector of size m.

From this, I'm supposed to determine if any processes are deadlocked? I think it's doable. So uh yeah let's get started

## The process

I need to define my data structures first. I think I can do multilayered arrays in C++ to make my matrices and vectors, so let's go with that

Ok first I need to relearn how to read the content of a file

UPDATE: I figured out the file reading and I made a cool interface. 

Now I need to make my data structures and then update my input file so I can assign the right data to them. After THAT, I need to actually make the program to detect if the stuff is deadlocked.