/************************ strcpy() ******************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    //prototype: char* strcpy(char* destination, const char* source); source is not modified that's why 'const'
    
    //strcpy is used to copy a string pointed by source(including null character) to the destination (character array)
    
    // char source[10] = "hello";
    // char destination[10];
    
    //printf("%s \n", strcpy(destination, source));
   // printf("%s \n", destination);
    // strcpy returns pointer to the first character of the string which is copied in the destination.
    
    //we can also chain together a series of strcpy calls
    // char string1[10] = "Hello";
    // char string2[10];
    // char string3[10];
    
    //strcpy(string3, strcpy(string2, string1));
    
   // printf("%s %s %s ", string1, string2, string3);
    
    //in the call to strcpy(str1, str2), there is no way the strcpy will check whether the string pointed by str2 will fit in str1
    // if length of string pointed by str2 is > length of str1 then it will be an undefined behaviour
    
    // char source1[6] = "hello";
    // char destination1[3];
    // printf("%s \n", strcpy(destination1, source1));
    //above snippet is very risky - can cause error like segmentation fault or memory corruption
    
    //solution
    //use strncpy function : strncpy(destination, source, sizeof(destination));
    //it copies only n characters, preventing overflow but may not null terminate if n is too small.
    char string1[6] = "hello";
    char string2[4];
    strncpy(string2, string1, sizeof(string2));
    //printf("%s", string2); //since string2 has no explicit null terminator, it may keep printing memory beyoin string2 - till it finds a random '\0'
    //manually add '\0' since strncpy will leave the string2 without a '\0' if the size of string1 is => size of string1
    
    string2[sizeof(string2)-1] = '\0';
    printf("%s", string2);
    
    return 0;
}
