//#include <iostream>
//
//struct myStruct {
//	void func() {
//		int localCounter = 10;
//		auto lambda = [=]() 
//		{
//			counter++;
//			std::cout << "inside lambda: " << counter << std::endl;
//			//localCounter++;
//			std::cout << "local counter: " << localCounter << std::endl;
//		};
//
//		lambda();
//
//		std::cout << "inside func: " << counter << "\n";
//	};
//
//	void func2() {
//		std::cout << "inside func2: " << counter << std::endl;
//	}
//	
//	int counter{ 0 };
//};
//
//int main() {
//
//	myStruct instance;
//	instance.func();
//	instance.func2();
//
//	instance.func();
//	instance.func2();
//
//	instance.func();
//	instance.func2();
//	//instance.func();
//	//instance.func();
//
//	return 0;
//}