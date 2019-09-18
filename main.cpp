#include <iostream>
#include "ForwardList.h"
#include "DoubleList.h"
using namespace std;

typedef ForwardList<int>::Iterator FNI;

int main() {
  
  ForwardList<int> fl;
  fl << 1 << 2 << 3 << 4 << 5;
  //cout << fl;

  
  for(FNI it = fl.begin(); it != fl.end(); it++){
    cout<<*it;
  }
  

  return 0;
}
