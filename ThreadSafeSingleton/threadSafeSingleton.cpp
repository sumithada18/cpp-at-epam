//#include <iostream> 
//#include <thread>
//#include <mutex>
//
//std::mutex m;

// unsafe class
//class Singleton {
//private:
//	int val;
//	Singleton() {
//		val = 10;
//	}
//	static Singleton* myPtr;
//public:
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	static Singleton* getInstance() {
//		if (myPtr == nullptr) {
//			myPtr = new Singleton();
//		}
//		return myPtr;
//	}
//	void printVal() {
//		std::cout << val << std::endl;
//	}
//	void updateVal(int x) {
//		val = x;
//	}
//};
//Singleton* Singleton::myPtr = nullptr;


// thread safe class
//class Singleton {
//private:
//	int val;
//	Singleton() {
//		val = 10;
//	}
//	static Singleton* myPtr;
//public:
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	static Singleton* getInstance() {
//		if (myPtr == nullptr) { // check without lock
//			std::lock_guard<std::mutex>lg(m);
//			if (myPtr == nullptr) { // check with lock
//				myPtr = new Singleton();
//			}
//		}
//		return myPtr;
//	}
//	void printVal() {
//		std::cout << val << std::endl;
//	}
//	void updateVal(int x) {
//		val = x;
//	}
//};
//Singleton* Singleton::myPtr = nullptr;


// thread safe singleton class

//class Singleton {
//private:
//	Singleton() {
//		printf("singleton instance created \n");
//	}
//public:
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	static Singleton& getInstance() {
//		static Singleton instance;
//		return instance;
//	}
//};
//void task() {
//	Singleton& instance = Singleton::getInstance();
//}
// from c++11 onwards local static varible is thread safe means if multiple threds try to create a static variblae
// the first thread to execute will make it 
// so when we run the code it prints "singleton instance created" only once becuase only one instance got created!




//int main() {
//	/*std::thread t1(
//		[]() {
//			Singleton::getInstance()->updateVal(20);
//			Singleton::getInstance()->printVal();
//		});
//	std::thread t2(
//		[]() {
//			Singleton::getInstance()->updateVal(30);
//			Singleton::getInstance()->printVal();
//		});*/
//	// problem: two threads will run parallely and can create two different Singleton objects - not the property of
//	// singleton class since there should be only one time instantiation of it
//
//	// solution: making the singleton class thread safe using thread synchronizaiton
//
//	// running the same 2 threads will result in sequential execution of those threads which does not hamper with the Singleton design property
//
//
//	std::thread t1(task);
//	std::thread t2(task);
//	std::thread t3(task);
//
//	t1.join();
//	t2.join();
//	t3.join();
//
//
//	return 0;
//}