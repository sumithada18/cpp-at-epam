// #include <iostream>
/*
class ITransport
{
public:
	virtual void deliver() = 0;
	virtual ~ITransport() {}
};

class IPackaging
{
public:
	virtual void pack() = 0;
	virtual ~IPackaging() {}
};

class Truck : public ITransport
{
public:
	void deliver() override {
		std::cout << "truck is delivering! \n";
	}
};

class Box : public IPackaging
{
public:
	void pack() override {
		std::cout << "Box is packed! \n";
	}
};

class ILogisticsFactory
{
public:
	virtual ITransport* createTransport() = 0;
	virtual IPackaging* createPackaging() = 0;
	virtual ~ILogisticsFactory() {}
};

class RoadLogisticsFactory : public ILogisticsFactory
{
public:
	ITransport* createTransport() { 
		return new Truck();
	}
	IPackaging* createPackaging() {
		return new Box();
	}
};

//class SeaLogisticsFactory : public ILogisticsFactory
//{
//public:
//	ITransport* createTransport() {
//		return new Ship();
//	}
//	IPackaging* createPackaging() {
//		return new 
//	}
//};

// now making for the ship
class Ship : public ITransport
{
public:
	void deliver() {
		std::cout << "Ship delivering! \n";
	}
};

class Container : public IPackaging {
public:
	void pack() {
		std::cout << "container packed! \n";
	}
};

class SeaLogisticsFactory : public ILogisticsFactory
{
public:
	ITransport* createTransport() {
		return new Ship();
	}
	IPackaging* createPackaging() {
		return new Container();
	}
};
*/
/*
int main() {

	ILogisticsFactory* factory = new RoadLogisticsFactory;
	ITransport* truck = factory->createTransport();
	IPackaging* package = factory->createPackaging();
	package->pack();
	truck->deliver();

	ILogisticsFactory* factory2 = new SeaLogisticsFactory();
	ITransport* ship = factory2->createTransport();
	IPackaging* container = factory2->createPackaging();
	package->pack();

	return 0;
}*/