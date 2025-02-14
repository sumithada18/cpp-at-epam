#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    // 1. malloc() -> memory allocation
    // 2. declared in <stdlib.h>

    void *malloc(size_t size); // 3. returns a void pointer which must be typcasted to the required data type.

    // 4. allocates raw, uninitialized m/n from heap
    // 5. returns null if m/m alloc'n fails.

    // 6.syntax:-
    int *ptr = (int *)malloc(5 * sizeof(int)); // allocates memory for 5 integers

    // 7. Handling failure
    int *ptr2 = (int *)malloc(10 * sizeof(int));
    if (!ptr2)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    else
    {
        printf("mmory allocated successfully!");
    }

    // 8. free() -> releases allocated memory back to the heap
    free(ptr);  // prevents m/m leaks
    ptr = NULL; // avoids dangling pointer

    /*

    A small program to see how important malloc is:-
    int n, i, *ptr;
    printf("enter no. of values: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n*sizeof(int));

    printf("\n enter the values: \n");
    for(i=0;i<n;i++){
        scanf("%d", (ptr+i));
    }

    printf("\n the entered values are: ");
    for(i=0;i<n;i++){
        printf("%d ",*(ptr+i));
    }

    free(ptr);

    */
    //malloc() -> dynamically allocates m/m for n integers on the heap,
    //without malloc(), a fized-size array would be needed, 
    // to potential m/m wastage or limitations
    return 0;
}