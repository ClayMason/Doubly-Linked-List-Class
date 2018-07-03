#include <iostream>
#include "dslist.h"
#include <assert.h>
#include <sstream>
#include <string>

template <class T>
std::string stringify (dslist<T>& _list) {
  std::stringstream ss;
  int count = 0;
  for ( typename dslist<T>::iterator itr = _list.begin(); itr != _list.end(); ++itr ) {
    ss << *itr << " ";
    ++count;
  }

  ss << "(" << _list.size() << ")";
  if ( count == _list.size() ) ss << "\tsize match ? yes\n";
  else ss << "\tsize match ? no\n";
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


  std::cout << "\n\nERASE TEST" << std::endl;
  dslist<std::string> c;
  c.push_back ("bravo");
  c.push_front ("alpha");
  c.push_back ("charlie");
  c.push_back ("delta");
  c.push_back ("epsilon");
  c.push_back ("foxtrot");
  c.push_back ("galio");
  assert(c.size() == 7);

  std::cout << "INIT C: " << stringify(c) << std::endl;

  // ERASING IN BETWEEN LIST
  list_iterator<std::string> c_itr = c.begin ();
  ++c_itr; ++c_itr;
  print_itr( c_itr, "ERASE ITR" );
  c.erase(c_itr);
  assert(c.size() == 6);
  std::cout << "AFTER ERASE #1 - C: " << stringify(c) << std::endl;
  c.erase(c_itr);
  assert(c.size() == 5);
  std::cout << "AFTER ERASE #2 - C: " << stringify(c) << std::endl;

  // ERASE AT START AND AT END OF LIST
  c_itr = c.begin ();
  c.erase(c_itr);
  assert(c.size() == 4);
  std::cout << "AFTER ERASE #3 - C: " << stringify(c) << std::endl;

  return 0;
}
