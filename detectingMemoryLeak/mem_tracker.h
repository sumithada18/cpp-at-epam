#pragma once
#ifndef MEM_TRACKER_H
#define MEM_TRACKER_H

#include <iostream>

struct Node {
    void* ptr;
    const char* file;
    int line;
    size_t size;
    Node* next;
};

void insert(void* ptr, const char* file, int line, size_t size);
void erase(void* ptr);
void reportLeaks();

void* operator new(size_t size, const char* file, int line);
void operator delete(void* ptr) noexcept;



#endif // MEM_TRACKER_H
