//This file contains the actual implementation while keeping Impl hidden.
#include <iostream>
#include "PublicInterface.h"

//definition of the hidden class - Impl
class PublicInterface::Impl
{
public:
	void getData() {
		std::cout << "data set in impl" << std::endl;
	}
	void setData() {
		std::cout << "data retrieved from impl" << std::endl;
	}
};

//constructor initializes the private implementation
PublicInterface::PublicInterface() : pImpl(std::make_unique<Impl>()) {}

//destructor (defined explicitly for unique_ptr to manage cleanup)
PublicInterface::~PublicInterface() = default;

// Public methods delegate work to Impl
void PublicInterface::getData() {
	pImpl->getData();
}

void PublicInterface::setData() {
	pImpl->setData();
}
