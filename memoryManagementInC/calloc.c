#include<stdio.h>
#include<stdlib.h>
//topic -> calloc() in C.
/*
-> calloc() stands for contiguous allocation, is used for DMA
-> unlike 'malloc()' it initializes allocated m/m to zero
-> allocates m/m in multiple smaller contigous blocks, each of equal size
-> return a 'void*' pointer to the allocated m/m block
*/
int main(){
    /*
    ---------- Syntax of calloc() -----------
    void* calloc(size_t num, size_t size);
    num -> no. of elements to allocate.
    size -> size of each el in bytes.
    returns a 'void*' pointer that must be typecasted.
    */


    //========= Example of calloc usage ==============
    int *arr;
    int n=5;

    //allocating m/m for 5 integerss using calloc()
    arr = (int*)calloc(n,sizeof(int));

    //-> If memory allocation fails, it returns `NULL`.
    if(arr==NULL){
        printf("m/m allocation failed");
        return 1;
    }

    //checking initialization
    printf("Array values after calloc(); \n");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }


    //free allocated m/m
    free(arr);
    return 0;
}

/*
Common calloc() errors:-

1. Forgetting to typecast
- int* ptr = calloc(5, sizeof(int)); //invalid in c++(valid in c)
- int* ptr = (int*)calloc(5,sizeof(int)); //correct

2. Forgetting to free memory (free())
- m/m must be freed to avoid m/m leaks

3.  Passing zero to the arguements 
- calloc(0, sizeof(int)) or calloc(5, 0) returns a valid pointer but does *not* allocate memory.

 4. Dereferencing NULL(failed allocation)
 - always check if calloc() returned NULL before using the pointer.

 =========================================
            When to Use calloc()
=========================================

✔ Use `calloc()` when:
   - You need zero-initialized memory.
   - You want to allocate memory for arrays dynamically.
   - You need to ensure no garbage values exist.

✔ Use `malloc()` when:
   - You **don’t** need zero-initialized memory (performance matters).
   - You want faster allocation.

=========================================
*/