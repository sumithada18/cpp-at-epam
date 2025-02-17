#include<stdio.h>
#include<stdlib.h>
/*
-----------------------------------------------
                free() in C
-----------------------------------------------
- The free() function is used to deallocate memory that was previously allocated using malloc(), calloc(), or realloc().
- It helps prevent memory leaks by releasing unused memory back to the system.
- After calling free(), the pointer still exists but becomes a **dangling pointer** if not set to NULL.
- Trying to access memory after freeing it results in **undefined behavior**.
- Freeing NULL is safe – it has no effect.
- Always free dynamically allocated memory before program termination.

*/

int main()
{
    int ch=1; //control variable for the lop
    int *ptr; //pointer for dynamic m/m alloc'n
    
    while(ch==1){
        printf("m/m leak demo \n");
        //allocating m/m fir 40k integers in each iteration
        ptr = (int*)malloc(40000*sizeof(int));
        
        printf("continue?? press 1 for yes! \n");
        scanf("%d", &ch);
        
        // Uncommenting the below line prevents memory leak
        //free(ptr);
    }

    return 0;
}
/*
-----------------------------------------------
        Observing Memory Leak
-----------------------------------------------
1. Run this program and keep pressing '1'.
2. Open **Task Manager > Details** and look for the running .exe file.
3. The memory usage (RAM) of the program **keeps increasing** as memory is never freed.
4. This happens because **malloc() keeps allocating new memory** without releasing the old one.
5. If you uncomment **free(ptr);**, the memory usage will remain stable since each allocation is freed.

*/