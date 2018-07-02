#include <iostream>
#include "dslist.h"
#include <assert.h>
#include <sstream>
#include <string>

template <class T>
std::string stringify (dslist<T>& _list) {
  std::stringstream ss;
  for ( typename dslist<T>::iterator itr = _list.begin(); itr != _list.end(); ++itr ) {
    ss << *itr << " ";
  }
  ss << "(" << _list.size() << ")";
  std::string temp = ss.str();

  return temp;
}

int main () {

  std::cout << "List Class Implementation" << std::endl;

  // test our doubly linked class
  dslist<int> a;

  a.push_back(32);
  a.push_front(5);
  a.push_back(10);
  a.push_back(56);
  assert(a.size() == 4);

  std::cout << stringify(a) << std::endl;

  return 0;
}
