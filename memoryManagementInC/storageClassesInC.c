#include <stdio.h>

// ----------------------------------------
// STORAGE CLASSES IN C
// ----------------------------------------

/*
Storage classes define:
1. Scope (Where variable is accessible)
2. Lifetime (How long variable exists)
3. Storage (Memory location)
4. Default value (If uninitialized)

Types:
1. auto     - Default local storage class.
2. register - Suggests storage in CPU registers.
3. static   - Retains value across function calls.
4. extern   - References global variables across files.
*/

// 1. AUTO STORAGE CLASS (Default for local variables)
void autoExample() {
    auto int x = 10;  // Auto variable (local)
    printf("Auto Variable: %d\n", x);
}

// 2. REGISTER STORAGE CLASS (Faster access, stored in CPU registers)
void registerExample() {
    register int y = 20;  // Suggests CPU register storage
    printf("Register Variable: %d\n", y);
}

// 3. STATIC STORAGE CLASS (Retains value across function calls)
void staticExample() {
    static int count = 0;  // Retains previous value
    count++;
    printf("Static Variable: %d\n", count);
}

// 4. EXTERN STORAGE CLASS (Access global variable across files)
int globalVar = 100;  // Global variable

void externExample() {
    extern int globalVar;  // Refers to the global variable
    printf("Extern Variable: %d\n", globalVar);
}

int main() {
    printf("\n--- STORAGE CLASS DEMO ---\n");

    autoExample();
    registerExample();

    printf("\nStatic Variable Behavior:\n");
    staticExample();  // First call
    staticExample();  // Second call (Value retained)

    externExample();

    return 0;
}

/*
KEY POINTS:
1. auto: Default, local scope, lifetime = function call.
2. register: CPU register (faster), local scope, no address (&var not allowed).
3. static (local): Retains value across function calls.
4. static (global): Restricts access to same file.
5. extern: Declares global variable in multiple files, actual storage elsewhere.

Quick Facts:
- auto and register are temporary (destroyed after function ends).
- static and extern have a lifetime till program ends.
- register storage is only a request; compiler may ignore it.
*/

