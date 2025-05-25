#include <iostream>
#include <memory>

struct Node {
	int data;
	// Using shared_ptr for next and prev creates the potential for cycles
	std::shared_ptr<Node> next;
	std::shared_ptr<Node> prev; // In a real doubly-linked list, 'prev' is often a weak_ptr to break cycles

	Node(int val) : data(val) {
		std::cout << "Node " << data << " created\n";
	}
	~Node() {
		// This destructor will NOT be called for Node 1 and 2 in this example
		// due to the cyclic dependency keeping their strong reference counts > 0.
		std::cout << "Node " << data << " deleted\n";
	}
};

int main() {
	/*
	 * STORY OF THE CYCLIC DEPENDENCY & MEMORY LEAK:
	 */

	// 1. Creation of Node 1:
	//    - Node object (data:1) created on heap.
	//    - Control Block for Node(1) created on heap. Strong Reference Count (SRC) = 1.
	//    - 'head' (stack variable, shared_ptr) owns Node(1).
	auto head = std::make_shared<Node>(1);     // Node(1) SRC: 1 (owned by 'head')

	// 2. Creation of Node 2:
	//    - Node object (data:2) created on heap.
	//    - Control Block for Node(2) created on heap. SRC = 1.
	//    - 'second' (stack variable, shared_ptr) owns Node(2).
	auto second = std::make_shared<Node>(2);   // Node(2) SRC: 1 (owned by 'second')

	// 3. Linking Node 1 to Node 2:
	//    - 'head->next' (a shared_ptr member of Node(1)) now also owns Node(2).
	//    - SRC for Node(2)'s Control Block increments.
	head->next = second;                       // Node(2) SRC: 1 (second) + 1 (head->next) = 2

	// 4. Linking Node 2 back to Node 1 (Creating the Cycle):
	//    - 'second->prev' (a shared_ptr member of Node(2)) now also owns Node(1).
	//    - SRC for Node(1)'s Control Block increments.
	second->prev = head;                       // Node(1) SRC: 1 (head) + 1 (second->prev) = 2

	/*
	 * At this point:
	 * - Node(1) is owned by: 'head' (stack) AND 'second->prev' (heap member of Node(2)). SRC = 2.
	 * - Node(2) is owned by: 'second' (stack) AND 'head->next' (heap member of Node(1)). SRC = 2.
	 */

	// 5. & 6. End of `main` scope:
	//    - 'second' (stack variable) goes out of scope.
	//      Its destructor decrements SRC for Node(2). Node(2) SRC becomes 2 - 1 = 1.
	//      Node(2) is NOT deleted as SRC is not 0 (still owned by 'head->next').
	//
	//    - 'head' (stack variable) goes out of scope.
	//      Its destructor decrements SRC for Node(1). Node(1) SRC becomes 2 - 1 = 1.
	//      Node(1) is NOT deleted as SRC is not 0 (still owned by 'second->prev').

	return 0; // Program ends

	/*
	 * THE AFTERMATH (MEMORY LEAK):
	 * - Node(1) still exists. Its SRC = 1 (solely due to 'second->prev').
	 * - Node(2) still exists. Its SRC = 1 (solely due to 'head->next').
	 * - No external shared_ptrs point to them. They are kept alive only by each other.
	 * - Their SRCs will never drop to 0. Destructors are not called. Memory is leaked.
	 *
	 * SOLUTION:
	 * - For one of the links (e.g., 'prev'), use std::weak_ptr<Node> prev;
	 *   A weak_ptr observes but doesn't contribute to the strong reference count, breaking the cycle.
	 */
}
