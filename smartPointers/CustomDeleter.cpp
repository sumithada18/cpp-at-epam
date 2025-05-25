#include <iostream>
#include <memory>
class Demo {
public:
	Demo() {
		std::cout << "Cons.. called\n";
	}
	~Demo() {
		std::cout << "Des.. called\n";
	}
};

int main() {
	// Step 1: Allocating array of 5 Demo objects
	Demo* darr = new Demo[5];

	// ❌ Problem: no memory deletion – causes memory leak if we forget to delete manually

	// Step 2: Wrap in smart pointer (RAII)
	// std::unique_ptr<Demo> uptr(darr);        // wrong: uses 'delete' (not delete[]) → only first destructor called
	// std::shared_ptr<Demo> sptr(darr);        // same issue

	// ✅ Step 3: Use custom deleter to correctly free array using delete[]
	auto customDeleter = [](Demo* d) { delete[] d; };

	// unique_ptr with custom deleter
	std::unique_ptr<Demo, decltype(customDeleter)> uptr(darr, customDeleter);

	// shared_ptr with custom deleter (alternative)
	// std::shared_ptr<Demo> sptr(darr, customDeleter);

	return 0;
}
