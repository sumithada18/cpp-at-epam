#include <stdio.h>

int main()
{
    //int num = 32;
    //printf("%d", num);
    
    /*
    double num1 = 3.141592653589793;
    printf("%lf \n", num1); 
    
    float num2 = 3.141592653589793;
    printf("%f", num2);
    */
    
    /*
    double num1 = 3.141592653589793;
    printf("%.15lf \n", num1); 
    
    float num2 = 3.141592653589793;
    printf("%.15f", num2);
    
    float (32-bit) stores only ~6-7 digits accurately, and extra digits may be rounded or incorrect.
    double (64-bit) stores 15-16 digits accurately, making it more precise.
    Even if you print more digits, float cannot store extra precision, while double can.
    */
    
    //long long num = 1098765;
    //printf("%lld", num);
    
    //-----Address format specifier----
    //int a = 10;
    //printf("%p", &a);
    
    //-----String format specifier-----
    //char a[] = {"Hello world"};
    //printf("%s", a);

     int num = 255;
    // %x prints an integer in lowercase hexadecimal (base 16).
    printf("%x \n", num);
    // %X prints an integer in uppercase hexadecimal (base 16).
    printf("%X \n", num);
    //Hexadecimal uses digits 0-9 and letters A-F (or a-f in lowercase).
    
    
    
    float num2 = 12345.6789;
    // %e prints a floating-point number in scientific notation with a lowercase 'e'.
    printf("Lowercase scientific notation: %e \n", num2);
    // %E prints the same value but with an uppercase 'E'.
    printf("Lowercase scientific notation: %E \n", num2);
    //12345.6789 -> 1.23456789 x 10^4 or 1.234568E+04 
    
    
    char* ptr = "sumit";
    printf("%10.2s", ptr);
    // 10 → Reserves 10-character width (right-aligned by default).
    // .2 → Prints only first 2 characters of the string.
    // If the string is shorter than 10, spaces are added for alignment.


    return 0;
}
