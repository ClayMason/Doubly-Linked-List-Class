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

  // PUSH BACK & PUSH FRONT WORKS FOR SIZE = 0 && SIZE > 0 CASES
  a.push_front(100);
  a.push_back(32);
  a.push_front(5);
  a.push_back(10);
  a.push_back(56);
  assert(a.size() == 5);

  std::cout << stringify(a) << std::endl;

  // POP-BACK TEST
  a.pop_back ();
  std::cout << "After pop-back: " << stringify(a) << std::endl;

  a.pop_front ();
  std::cout << "After pop-front: " << stringify(a) << std::endl;

  // single-item case pop-back & pop-front test.
  dslist<double> b;

  b.push_front(4.5);
  std::cout << "Init b: " << stringify(b) << std::endl;
  b.pop_front ();
  std::cout << "(b) : pop_front () => " << stringify(b) << std::endl;

  b.push_back(50.2);
  std::cout << "Init b: " << stringify(b) << std::endl;
  b.pop_back ();
  std::cout << "(b) : pop_back () => " << stringify(b) << std::endl;

  b.push_front (24.5);
  std::cout << "Init b: " << stringify(b) << std::endl;
  b.pop_back ();
  std::cout << "(b) : pop_back () => " << stringify(b) << std::endl;

  b.push_back(65.24);
  std::cout << "Init b: " << stringify(b) << std::endl;
  b.pop_front ();
  std::cout << "(b) : pop_front () => " << stringify(b) << std::endl;

  return 0;
}
