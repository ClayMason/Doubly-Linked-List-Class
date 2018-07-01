#ifndef dslist_h_
#define dslist_h_

#include <cassert>

// --------------------------------------------------------
// NODE CLASS

template <class T>
class Node {
  public:
    Node () : next_(NULL), prev_(NULL) {}

    //  member variables
    Node<T>* prev_;
    Node<T>* next_;
};

#endif
