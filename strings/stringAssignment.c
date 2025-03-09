#include <stdio.h>
#include <string.h>
//recursive function to find length of string - using one parameter only
int recur(char* ptr) {
	if(*ptr == '\0') return 0;
	return 1+recur(ptr+1);
}

int main()
{
	char *str = "hello";
	printf("%s \n", str);

	int len = recur(str);
	printf("length is: %d \n", len);

	//==========================================================================

	//strstr() : function that returns first occurence of string in the another string
	//syntax: char *strstr(const char* s1, const char* s2);

	//example: s1: main string, s2: sub-string to search in s1
	//strstr() -> returns pointer to the first character of the found s2 in s1 otherwise a nullptr
	char s1[] = "geeksforgeeks";
	char s2[] = "for";

	char* ptr = strstr(s1, s2);
	if(ptr) {
		printf("first occurence of s2(%s) in s1(%s) is at: %s \n", s2, s1, ptr);
	}
	else {
		printf("string not found");
	}

	//==========================================================================
	//strtok() in c: strtok is a C function that splits a string into tokens based on specified delimiters, modifying the original string.
	//It modifies the original string by replacing the delimiter with \0 (null character), so the tokens become separate strings.
	
	char str2[] = "sumit-is-at-epam";
	char* token  = strtok(str2, "-"); //finds "-", replaces it with \0 and return "sumit"
	printf("%s \n", token); //prints sumit
	
	//when we do it again it still gives sumit 
	//char* token2 = strtok(str2, "-");
	//printf("%s", token2);
	
	/*
	Passing the original string again resets `strtok()`, making it start from the beginning. 
	To continue tokenizing, pass `NULL` so `strtok()` uses its internal pointer.
	*/
	
	char* token3 = strtok(NULL, "-");
	printf("%s \n", token3);
	
	//example 2;
	
	char str3[] = "hey-my-name-is-harry-potter";
	char* temp = strtok(str3, "-");
	// Keep printing tokens while one of the
    // delimiters present in str3[].
	while(temp!=NULL){
	    printf("%s \n", temp);
	    temp = strtok(NULL, "-");
	}


	/*
 char str[] = "abcabcabc";
    char* ptr = strstr(str+4, "abc");
    if(ptr){
     printf("%s", ptr);   
    }
    else{
        printf("error");
    }
	*/

	return 0;
}
