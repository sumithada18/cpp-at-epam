// #include <iostream>
/*
 Factory Pattern in one line:
 - Provide a simple way to create objects without tying your code to concrete classes.

How it works:
 - Define a product interface.
 - Implement concrete products.
 - Have a factory function (or class) that returns the interface type, choosing the right concrete product internally.
*/

/*
// 1) Product Interface
struct Animal {
    virtual void speak() = 0;
    virtual ~Animal() = default;
};
// 2) Concrete products
struct Dog : Animal
{
    void speak() {
        std::cout << "woof! \n";
    }
};

struct Cat : Animal
{
    void speak() {
        std::cout << "meow! \n";
    }
};

// 3) Factory function
Animal* createAnimal(const std::string& name) {
    if (name == "dog") return new Dog();
    if (name == "cat") return new Cat();
    return nullptr;
}


// anohter example
class ITransport
{
public:
    virtual void deliver() = 0;
    virtual ~ITransport() = default;
};

class Truck : public ITransport
{
public:
    void deliver() override
    {
        printf("delivering by truck \n");
    }
};


class Ship : public ITransport
{
    void deliver() override
    {
        printf("delivering by ship \n");
    }
};

//enum struct transportType { TRUCK, SHIP };

// factory class
//class TransportFactory
//{
//public:
//    static ITransport* getObject(transportType type) {
//        if (type == transportType::TRUCK) {
//            return new Truck();
//        }
//        if (type == transportType::SHIP) {
//            return new Ship();
//        }
//        return nullptr;
//    }
//};

// more extensible code type for the same example: 
// Use this version : `ITransportFactory + Concrete Factories`, When : System is growing, you expect new product types.Follows SOLID.
class ITransportFactory {
public:
    virtual ITransport* getObject() = 0;
    virtual ~ITransportFactory() {}
};

class ShipFactory : public ITransportFactory
{
public:
    ITransport* getObject() override
    {
        return new Ship();
    }
};

class TruckFactory : public ITransportFactory
{
public:
    ITransport* getObject() override
    {
        return new Truck();
    }
};
*/

/*
int main()
{
    // example 1 
    // Animal* pet1 = createAnimal("dog");
    // Animal* pet2 = createAnimal("cat");

    // pet1->speak();
    // pet2->speak();

    // delete pet1;
    // delete pet2;

    // You never directly create the object using new in client code,
    // you just ask the factory and it will decide at runtime which concrete object to return.

    // This way:
    // Adding new types = change only factory logic.
    // No need to touch or break client code.


    // example2
    /*ITransport* ptr = nullptr;
    auto type = transportType::TRUCK;
    ptr = TransportFactory::getObject(type);
    ptr->deliver();
    delete ptr;*/

    // we could code this using RAII as well - smart pointers 

    // example 2 with better extensibilty, following SOLID and best for grwoing code
    //ITransportFactory* truckFactory = new TruckFactory();
    //ITransportFactory* shipFactory = new ShipFactory();
    
    //ITransport* truck = truckFactory->getObject();
    //ITransport* ship = shipFactory->getObject();

    //truck->deliver();
    //ship->deliver();

    //return 0;

    
//the core idea is always the same:
// - Have an abstraction (interface or base class) for the product.
// - Implement concrete products that fulfill that abstraction.
// - Encapsulate creation in a factory (function or class) so clients only deal with the abstraction.

// }


