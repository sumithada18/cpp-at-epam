//#include <iostream>
//#include <stack>
//
//template<typename T>
//void print(std::stack<T>st) {
//	while (!st.empty()) {
//		std::cout << st.top() << "\n";
//		st.pop();
//	}
//}
//
//void insertAtEnd(std::stack<int>&st, int val) {
//	//base case
//	if (st.empty()) {
//		st.push(val);
//		return;
//	}
//	int topVal = st.top();
//	st.pop();
//	insertAtEnd(st, val);
//	st.push(topVal);
//}
//
//void reverse(std::stack<int>&st) {
//	if (st.empty()) {
//		return;
//	}
//	int topVal = st.top();
//	st.pop();
//	reverse(st);
//	insertAtEnd(st,topVal);
//}
//
//int main() {
//	// std::stack - comtainer adapter that follows LIFO
//	std::stack<int>st;
//	
//	// insertion
//	st.push(12);
//	st.push(11);
//	st.push(13);
//	st.push(15);
//
//	// deletion: from one end only
//	st.pop();
//
//	// printing stack
//	/*while (!st.empty()) {
//		std::cout << st.top() << "\n";
//		st.pop();
//	}*/ // numbers will be printed in the reverse order of insertion
//
//	//function to insert in the end of the stack
//	std::stack<int>stk;
//	stk.push(12);
//	stk.push(3);
//	stk.push(44);
//	stk.push(5);
//	/*int val = 69;
//	insertAtEnd(stk,val);
//	while (!stk.empty()) {
//		std::cout << stk.top() << "\n";
//		stk.pop();
//	}*/
//
//	// function to reverse the stack
//	std::cout << "before reversal \n";
//	print(stk);
//
//	reverse(stk);
//
//	std::cout << "after reversal \n";
//	print(stk);
//
//	return 0;
//}