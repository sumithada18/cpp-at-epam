#include <stdio.h>
#include <stdlib.h>
// Topic: realloc() in C.
/*
1. realloc() -> "reallocation of memory"
2. Main purpose: to "resize" the memory after already allocated with malloc or calloc
3. Resize means to "increase or decrease" memory
4. You can only use realloc if you have already allocated memory using malloc or calloc, else it is impossible to use realloc
5. it accept two arguments: (a) previous allocated pointer (b) new memory size
6. realloc returns void*
7. when it increases memory, it will not lose the previous content
8. after using realloc, you should free it.
*/

int main()
{
    // step 1. allocate m/m for 3 integers
    int *ptr = (int *)malloc(3 * sizeof(int));

    // check if m/m alloc'n was successfull
    if (ptr == NULL)
    {
        printf("alloc'n failed");
        return 1;
    }

    // initializing the m/m
    for (int i = 0; i < 3; i++)
    {
        *(ptr + i) = i + 1; // assigned values 1,2,3
    }

    /*
    - realloc() resizes previously allocated memory.
        - If more space is available at the same location, it extends in place.
        - Otherwise, it allocates a new memory block, copies old data, and frees the old block.
        - Returns a pointer to the new memory or NULL if reallocation fails.
    */

    // step2. reallocate m/m to hold 5 integers
    ptr = (int *)realloc(ptr, 5 * sizeof(int));
    /*
    Bad practice:-
    int* newPtr = (int*)realloc(ptr, sizeof(int));
    Why ?
    -> if realloc fails, it returns NULL, and you may lose the original ptr, leading to a memory leak.
    Safer way:-
    int* newPtr = (int*) realloc(ptr, 5 * sizeof(int));
if (newPtr) {
    ptr = newPtr;  // Assign only if realloc succeeds
} else {
    // Handle memory allocation failure
}
    */

    // Check if reallocation was successful
    if (ptr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    /*  
         **Memory Behavior After realloc()**
        - If the original block is extended, old data remains unchanged.
        - If a new block is allocated, old data is copied.
        - The newly allocated portion remains **uninitialized** (garbage values).
    */

    //initialize newly allocated m/m
    for(int i=3;i<5;i++){
        ptr[i]=i+1; //assigning values 4,5
    }

    //step 3: print the values
    for(int i=0;i<5;i++){
        printf("%d ",*(ptr+i));
    }

    // Step 4: Free the allocated memory
    free(ptr);
}

/*
Miscellaneous
If we do ptr = (int*) realloc(NULL, 5 * sizeof(int));, 
it will behave like malloc() and allocate memory for 5 integers.
*/