#include <iostream>
#include "PublicInterface.h"

int main() {

	PublicInterface obj;
	obj.getData();
	obj.setData();

	return 0;
}

/*
//benefit of using pimpl:
-> Encapsulation: Hides implementation details.
-> publicInterface.cpp is hidden in the sense that the user doesn't directly see it because it's compiled into the final binary.
-> If you modify Impl (the hidden implementation class), only publicInterface.cpp needs to be recompiled, while publicInterface.h remains unchanged. This significantly reduces compilation time, especially in large projects.
-> Binary compatibility: If PublicInterface's API remains the same, only publicInterface.cpp needs rebuilding, not the whole project.
*/