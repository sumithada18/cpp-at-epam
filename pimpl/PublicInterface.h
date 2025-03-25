// This is the class exposed to the user. It only declares methods and stores a pointer to the hidden implementation.
#ifndef PUBLIC_INTERFACE
#define PUBLIC_INTERFACE

#include <memory>

class PublicInterface {
public:
	PublicInterface(); //constructor 
	~PublicInterface(); //destructor

	void getData();
	void setData();
private:
	class Impl; //forward declaration of the hidden class
	std::unique_ptr<Impl>pImpl; //pointer to the hidden class
};

#endif 