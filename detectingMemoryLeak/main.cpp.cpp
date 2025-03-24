#include<iostream>
#include "mem_tracker.h"
#define new new(__FILE__, __LINE__)

int main() {
    int* p1 = new int(10); //add: xyz line 6 mem: 4
    int* p2 = new int[5]; //add: xyz line 7 mem: 20

    delete p1; // No leak
    // Forgot to delete p2 -> Leak will be reported
    delete[] p2;

    reportLeaks(); // Should report p2 if not deleted

    return 0;
}


/*

int* p1 = new int(10);
the preprocessor replaces 'new' with new(__FILE__, __LINE__) so it becomes:
int* p1 = new(__FILE__, __LINE__) int(10);

__FILE__ and __LINE__ are preprocessor macros in C and C++. 
__FILE__ -> Expands to the current file name as a string literal. ex: __FILE__ becomes "main.cpp" 
__LINE__ -> Expands to the current line number in the source file as an integer. ex: __LINE__ appears on line 25

*/