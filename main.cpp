#include <iostream>
#include "ForwardList.h"
using namespace std;

int main() {
	
	ForwardList<int> fl;
	cout << fl.empty() << endl;
	fl.push_back(10);
	fl.push_back(20);
	fl.push_front(30);
	fl.push_front(40);
	fl.print();
	fl.pop_front();
	fl.pop_back();
	fl.print();
	cout << fl.empty() << endl;
	cout << fl.size() << endl;
	
}