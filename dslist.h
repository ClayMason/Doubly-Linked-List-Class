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


// forward declaration of ds list b/s it is referenced in list_iterator
template <class T> class dlist;
// --------------------------------------------------------
// LIST ITERATOR CLASS
template <class T>
class list_iterator {
  private:
    // representation
    Node<T>* ptr_;

  public:
    list_iterator () : ptr_(NULL) {}
    list_iterator ( Node<T>* p ) : prt_(p) {}
    list_iterator ( const list_iterator<T>& old ) : ptr_(old.ptr_) {}

    // operator overloading
    // ASSIGNMENT OPERATOR
    list_iterator<T>& operator= (const list_iterator<T>& old)
      { this->ptr_ = old.ptr_; return *this; }
    // DEREFERENCE OPERATOR - return what ptr_ points at
    T& operator* () { return ptr_->value; }
    // INCREMENT & DECREMENT OPERATORS
    list_iterator<T>& operator++ () { // ++iter
      // increment iterator, then return new state
      ptr_ = ptr_->next_;
      return *this;
    }
    list_iterator<T>& operator++ (int) { // iter++
      // return current state of iterator, then increment it
      list_iterator<T>& temp(*this);
      ptr_ = ptr_->next;
      return temp;
    }
    list_iterator<T>& operator-- () { // --iter
      // decrement iterator, then return new state
      pre_ = pre_->prev_;
      return *this;
    }
    list_iterator<T>& operator-- (int) {
      // return current iterator state, then decrement it
      list_iterator<T>& temp(*this);
      ptr_ = ptr_->prev_;
      return temp;
    }

};


#endif