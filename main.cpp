#include <iostream>
#include "dslist.h"
#include <assert.h>
#include <sstream>

template <class T>
char* stringify (dslist<T>& _list) {
  std::stringstream ss;
  for ( typename dslist<T>::iterator itr = _list.begin(); itr != _list.end(); ++itr ) {
    ss << *itr << " ";
  }
  ss << "(" << _list.size() << ")";

  return (char*) ss.str();
}

int main () {

  // test our doubly linked class
  dslist<int> a;

  a.push_front(5);
  a.push_back(10);

  std::cout << stringify(a) << std::endl;
  assert(a.size() == 3);

  return 0;
}
