#include <iostream>
#include "mem_tracker.h"
#include <cstdlib>  // For malloc and free
#include <new>

Node* head = nullptr;

// Insert allocation record
void insert(void* ptr, const char* file, int line, size_t sizePtr) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) { // Safety check
        std::cerr << "memory allocation for tracking node failed \n";
        return;
    }
    newNode->ptr = ptr;
    newNode->file = file;
    newNode->line = line;
    newNode->size = sizePtr;
    newNode->next = head;
    head = newNode;
}

// Remove allocation record
void erase(void* ptrToFind) {
    Node* curr = head;
    Node* prev = nullptr;
    while (curr) {
        if (curr->ptr == ptrToFind) {
            if (prev) { //it's a node from somehwere between in the list
                prev->next = curr->next;
            }
            else { //it's the head node
                head = curr->next;
            }
            free(curr);
            curr = nullptr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

//better approach: 
//void erase(void* ptr) {
//    Node** curr = &head;
//    while (*curr) {
//        if ((*curr)->ptr == ptr) {
//            Node* temp = *curr;
//            *curr = (*curr)->next;
//            free(temp);
//            return;
//        }
//        curr = &((*curr)->next);
//    }
//}

// Report memory leaks
void reportLeaks() {
    if (head != NULL) {
        Node* temp = head;
        while (temp) {
            std::cout << "Memory leak detected of "<< temp->size << " bytes at " << temp->file << " and line " << temp->line
                << " (Address: " << temp->ptr << ")\n";
            temp = temp->next;
        }
    }
    else {
        std::cout << "no memory leak \n";
    }
}

// Overloaded new operator
void* operator new(size_t size, const char* file, int line) {
    void* ptr = malloc(size);
    if (!ptr) throw std::bad_alloc();
    insert(ptr, file, line, size);
    return ptr;
}

// Overloaded delete operator
void operator delete(void* ptr) noexcept {
    if (!ptr) return;
    erase(ptr);
    free(ptr);
}
