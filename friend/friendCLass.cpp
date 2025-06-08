/*
#include <iostream>

// A friend class is a class whose members are granted full access 
// to the private and protected members of another class (the one that declared it as a friend).

class MyFriendClass;
class MyClass {
public:
	MyClass(int pvdata, int prdata) : privateData(pvdata), protectedData(prdata){}
	// friend MyFriendClass; // define it anywhere, be it 
private:
	int privateData;
	void privateMethod() {
		std::cout << "MyClass::privateMethod()\n";
	}
	friend MyFriendClass;
protected:
	int protectedData;
	// friend MyFriendClass; // no matter where you define it, access specifiers don't work for it 
};

class MyFriendClass {
public:
	void accessMyClassMembers(MyClass& obj) {
		std::cout << obj.privateData << "\n";
		obj.privateMethod();
		std::cout << obj.protectedData << "\n";
	}
};


int main() {
	MyClass mc(10, 12);
	MyFriendClass mfc;
	mfc.accessMyClassMembers(mc);
}
*/