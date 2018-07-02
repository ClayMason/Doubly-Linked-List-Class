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

  std::cout << "Starting push_front () " << std::endl;
  a.push_front(5);
  std::cout << "finished push_front () " << std::endl;
  a.push_back(10);
  std::cout << "finished push_back () " << std::endl;
  assert(a.size() == 3);

  std::cout << stringify(a) << std::endl;

  return 0;
}
