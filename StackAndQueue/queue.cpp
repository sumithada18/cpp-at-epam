#include <iostream>
#include <queue>

template<typename T>
void print(std::queue<T>q) {
	// queue does not support begin() / end() so this is how we traverse and print
	// the elements of the queue!
	while (!q.empty()) {
		std::cout << q.front() << " ";
		q.pop(); // deletion in queue happens from the front
	}
}

class Test {
public:
	Test(int x) {
		std::cout << "def. cons.. \n";
	}
	Test(const Test& obj) {
		std::cout << "copy cons.. \n";
	}
};

int main() {
	// container adaptor that follows FIFO
	std::queue<int>q;
	for (int i = 1;i <= 10;i*=2) {
		q.push(i); // insertion in quue happens from the back
	}
	print(q);

	// size of queue
	std::cout << "size of queue: " << q.size() << "\n";

	// is queue empty or not
	std::cout << "q empty ?" << (q.empty() ? "yes" : "no") << "\n";

	// emplace - construction in place
	std::queue<Test>qt;
	qt.push(10); // creates a temporary object then copies

	std::cout << "\n";

	qt.emplace(20); // constructs directly inside queue!

	std::queue<Test>qt2;

	qt2.swap(qt);

	std::cout << "size of qt after swap: " << qt.size() << "\n";
	std::cout << "size of qt2 after swap: " << qt2.size() << "\n";

	return 0;
}