#include <iostream>
#include "ForwardList.h"
using namespace std;

int main() {
	
	ForwardList<int> fl;
	cout << fl.empty() << endl;
	fl.push_back(20);
	fl.push_back(50);
	fl.push_front(3);
	fl.push_front(49);
	fl.sort();
	cout << fl;
	fl.pop_front();
	fl.pop_back();
	cout << fl;
	cout << fl.empty() << endl;
	cout << fl.size() << endl;
	cout << fl[1] << endl;
	fl.reverse();
	cout << fl;
	fl << 5;
	fl << 10;
	fl << 20;
	cout << fl;
	fl.erase(2);
	cout << fl;
	fl.insert(1, 100);
	cout << fl;
	fl.drop(20);
	cout << fl;

	return 0;
}
