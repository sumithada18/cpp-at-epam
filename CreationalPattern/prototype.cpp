
// #include <iostream>

/*
 The main goal of Prototype Design Pattern is to create new objects by copying an existing object (the "prototype"),
 rather than creating objects from scratch using constructors.
 
 How it Works in C++ :

=> Prototype Interface/Abstract Class:
 - Define a common interface or abstract base class for all objects that can be cloned.
 - his interface typically declares a virtual (often pure virtual = 0) clone() method.
 - The clone() method is responsible for creating and returning a new object that is a copy of the current object.

=> Concrete Prototypes:
 - These are the actual classes whose objects you want to copy.
 - They implement the Prototype interface.
 - Each concrete prototype provides its own implementation of the clone() method. This method usually involves:
	- Creating a new instance of its own class (e.g., using new ConcretePrototype(*this);).
 - Relying on the copy constructor or copy assignment operator to copy the state from the original object (this) to the new object.
Crucially: Handling deep vs. shallow copying correctly.

=> Client:
 - The client code holds a reference or pointer (preferably a smart pointer) to a Prototype object.
 - When the client needs a new object of that type, instead of calling new ConcretePrototype(...), it calls the clone() method on its existing prototype instance.
 - The client receives a pointer to a new object, which is a copy of the prototype, without needing to know the prototype's concrete class.
*/

/*
class Shape
{
public:
	virtual Shape* clone() = 0;
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Circle : public Shape
{
	double radius;
public:
	Circle(int r) : radius(r) {}
	Shape* clone() override
	{
		return new Circle(*this); // copy constructor invoked
	}
	void draw() override {
		std::cout << "circle drawn with radius: " << radius << "\n";
	}
};

class Rectangle : public Shape
{
	int length, width;
public:
	Rectangle(int len, int wid) : length(len), width(wid) {}
	Shape* clone() override {
		return new Rectangle(*this); // copy constructor invoked
	}
	void draw() override {
		std::cout << "rectangle drawn with len: "
			<< length << " and wid: " << width << "\n";
	}
};

int main() {	
	Shape* original = new Circle(10);
	Shape* copy = original->clone();

	copy->draw();
	return 0;


	// One key benefit of the Prototype Design Pattern is avoiding costly object creation—for example, loading a file from disk once and then cloning the object instead of reloading it. 
	// Other benefits include faster object creation, reduced resource usage, and the ability to create copies of objects without depending on their concrete classes.

}
*/
