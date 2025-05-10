#include <iostream> 
#include <thread>
#include <mutex>

std::mutex m;

class Singleton {
private:
	int val;
	Singleton() {
		val = 10;
	}
	static Singleton* myPtr;
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton* getInstance() {
		static Singleton instance;
		return &instance;
	}
	void printVal() {
		std::lock_guard<std::mutex>lg(m);
		std::cout << val << std::endl;
	}
	void updateVal(int x) {
		std::lock_guard<std::mutex>lg(m);
		val = x;
	}
};
Singleton* Singleton::myPtr = nullptr;

int main() {
	std::thread t1(
		[]() {
			Singleton::getInstance()->updateVal(20);
			Singleton::getInstance()->printVal();
		});
	std::thread t2(
		[]() {
			Singleton::getInstance()->printVal();
		});

	t1.join();
	t2.join();
}