#ifndef dslist_h_
#define dslist_h_

#include <cassert>
#include <iostream>
#include <string>

// --------------------------------------------------------
// NODE CLASS

template <class T>
class Node {
  public:
    Node () : next_(0), prev_(0) {}
    Node (T& new_val) : value(new_val), next_(0), prev_(0) {}

    //  member variables
    T value;
    Node<T>* next_;
    Node<T>* prev_;
};


// forward declaration of ds list b/s it is referenced in list_iterator
template <class T> class dslist;
// --------------------------------------------------------
// LIST ITERATOR CLASS
template <class T>
class list_iterator {
  private:
    // representation
    Node<T>* ptr_;

  public:
    list_iterator () : ptr_(0) {}
    list_iterator ( Node<T>* p ) : ptr_(p) {}
    list_iterator ( const list_iterator<T>& old ) /*: ptr_(old.ptr_)*/ {
      this->ptr_ = old.ptr_;
    }

    template <class U>
    friend void print_itr(const list_iterator<U>& itr, const std::string label);

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
      list_iterator<T> temp(*this);
      this->ptr_ = this->ptr_->next_;

      return temp;
    }
    list_iterator<T>& operator-- () { // --iter
      // decrement iterator, then return new state
      ptr_ = ptr_->prev_;
      return *this;
    }
    list_iterator<T>& operator-- (int) { // iter--
      // return current iterator state, then decrement it
      list_iterator<T>& temp(*this);
      ptr_ = ptr_->prev_;
      return temp;
    }

    // dslist class needs to access list_iterator's ptr_ private variable
    // so, we make it friends with list_iterator<T> class
    friend class dslist<T>;

    // COMPARISON OPERATOR
    bool operator== (const list_iterator<T>& r) const {
      return this->ptr_ == r.ptr_;
    }
    bool operator!= (const list_iterator<T>& r) const {
      return this->ptr_ != r.ptr_;
    }

};

// HELPER
template <class T>
void print_itr (const list_iterator<T>& itr, const std::string label_) {
  std::cout << "---------------------------------------" << std::endl;
  std::cout << "Print Iterator - " << label_ << std::endl;
  std::cout << "Address: " << &itr << std::endl;
  std::cout << "ptr null ? ";
  if (itr.ptr_ == 0) std::cout << "yes" << std::endl;
  else {
    std::cout << "No" << std::endl;
    std::cout << "\t value = " << itr.ptr_->value << std::endl;
    std::cout << "\t prev_ null ? ";
    if (itr.ptr_->prev_ == 0) std::cout << "yes" << std::endl;
    else std::cout << "no" << std::endl;
    std::cout << "\t next_ null ? ";
    if (itr.ptr_->next_ == 0) std::cout << "yes" << std::endl;
    else std::cout << "no" << std::endl;
  }
  std::cout << "---------------------------------------\n" << std::endl;
}

template <class T>
void print_node (const Node<T>& n, const std::string label_) {
  std::cout << "---------------------------------------" << std::endl;
  std::cout << "Node: " << label_ << std::endl;
  std::cout << "\tValue => " << n.value << std::endl;
  std::cout << "\tprev_ null ? ";
  if ( n.prev_ == 0 ) std::cout << "yes" << std::endl;
  else std::cout << "no => (prev_ = "<< n.prev_->value<<")" << std::endl;
  std::cout << "\tnext_ null ? ";
  if ( n.next_ == 0 ) std::cout << "yes" << std::endl;
  else std::cout << "no => (next_ = "<< n.next_->value<<")" << std::endl;

  std::cout << "---------------------------------------\n" << std::endl;
}

// --------------------------------------------------------
// DS LIST CLASS IMPLEMENTATION
template <class T>
class dslist {
  private:
    // private helper functions
    /*TODO -- DONE*/ void copy_list (const dslist<T>& old);
    /*TODO*/ void destroy_list ();

    // REPRESENTATION
    Node<T>* head_;
    Node<T>* tail_;
    unsigned int size_;

  public:
    // default constructor, assignment constructor, copy constructor,
    // & deconstructor
    dslist () : head_(0), tail_(0), size_(0) {} // 0 for NULL
    dslist (const dslist<T>& old) { this->copy_list(old); }
    /*TODO -- DONE*/ dslist<T>& operator= (const dslist<T>& old);
    ~dslist () { this->destroy_list(); }

    // SIMPLE ACCESSORS
    unsigned int size () const { return size_; }
    bool empty () const { return head_==0; }

    // SIMPLE MODIFIERS
    void clear () { this->destroy_list(); }

    // read / write access to contents
    const T& front () const { return head_->value; }
    T& front () { return head_->value; }
    const T& back () const { return tail_->value; }
    T& back () { return tail_->value; }

    // modify linked list structure
    /*TODO -- DONE*/ void push_front (const T& v);
    /*TODO -- DONE*/ void pop_front ();
    /*TODO -- DONE*/ void push_back (const T& v);
    /*TODO -- DONE*/ void pop_back ();

    // iterator modifier functions
    typedef list_iterator<T> iterator;
    /*TODO -- DONE*/ iterator erase (iterator itr);
    /*TODO -- DONE*/ iterator insert (iterator itr, const T& v);
    iterator begin () { return iterator(head_); }
    iterator end () { return iterator(0); }
};


// IMPLEMENTATIONS !!!
template <class T>
dslist<T>& dslist<T>::operator= (const dslist<T>& old) {
  // check for self assignment
  if ( &old != this ) {
    this->destroy_list();
    this->copy_list(old);
  }

  return *this;
}

template <class T>
void dslist<T>::push_front (const T& v) {
  // add v to the front -- relinking

  if ( this->size_ == 0 ) {
    head_ = new Node<T>;
    head_->value = v;
    tail_ = head_;
  }
  else {
    // make a new node for v
    Node<T>* v_node;
    v_node = new Node<T>;
    v_node->value = v;

    list_iterator<T> _first = this->begin ();
    _first.ptr_->prev_ = v_node;
    v_node->next_ = _first.ptr_;
    this->head_ = v_node;
  }

  ++size_;
}

template <class T>
void dslist<T>::pop_front () {
  // remove the item in the front
  if ( this->size_ > 0 ) {
    Node<T>* to_remove = this->head_;
    this->head_ = (++(this->begin())).ptr_;

    to_remove->next_ = 0;
    if (this->head_ != 0) head_->prev_ = 0;

    delete to_remove;
    -- size_;
  }
}

template <class T>
void dslist<T>::push_back (const T& v) {
  // add v to the end of the list
  if (this->size_ == 0) {
    head_ = new Node<T>;
    head_->value = v;
    tail_ = head_;
  }
  else {
    Node<T>* to_add = new Node<T>;
    to_add->value = v; // set the node value to v (object to add to list)
    to_add->prev_ = tail_; // make the end of the list point forward (next_) to v
    tail_->next_ = to_add; // make v point back to end of list (prev_)

    tail_ = to_add; // now, make to_add the new end of list by assigning it to tail_
  }

  ++size_; // inc size
}

template <class T>
void dslist<T>::pop_back () {
  if ( this->size_ > 0 ) {
    // remove the item at the end of the list
    Node<T>* to_remove = tail_;
    tail_ = tail_->prev_;
    if (tail_ != 0) tail_->next_ = 0;
    to_remove->prev_ = 0;

    delete to_remove;
    --size_;
  }
}

template <class T>
typename dslist<T>::iterator dslist<T>::erase (iterator itr) {
  if ( itr.ptr_ != 0 ) {
    // remove the object that the iterator is pointing at in this list.
    print_itr(itr, "TO ERASE");
    Node<T>* to_left = itr.ptr_->prev_;
    Node<T>* to_right = itr.ptr_->next_;

    itr.ptr_->next_ = 0;
    itr.ptr_->prev_ = 0;

    delete itr.ptr_;
    assert(itr.ptr_ == 0);

    // make sure the Node pointers are not null before accessing properties of it1
    if (to_left != 0) to_left->next_ = to_right;
    if (to_right != 0) to_right->prev_ = to_left;
    --this->size_;

    print_itr(iterator(to_right), "RETURN AFTER ERASE");
    return iterator(to_right);
  }
  return 0;
}

template <class T>
typename dslist<T>::iterator dslist<T>::insert (iterator itr, const T& v) {
  // insert v after the Node that itr's ptr_ points to
  Node<T>* to_add;
  *to_add = new Node<T>;
  to_add->value = v;

  if ( itr.ptr_ == 0 ) // if the iterator is null ... insert to end ? b/c end () also returns null iteratror
  {
    tail_->next_ = to_add;
    to_add->prev_ = tail_;
    tail_ = to_add;
  } else {
    // otherwise, the itr should be pointing at a node within the list
    Node<T>* to_right = itr.ptr_->next_;
    Node<T>* to_left = itr.ptr_;

    if (to_right != 0) to_right->prev_ = to_add; // want to make sure to_right is not null
    to_left->next_ = to_add; // to_left cannot be null b/c we already cheked in 1st if -- so no need to double check

    to_add->next_ = to_right;
    to_add->prev_ = to_left;
    ++this->size_;
  }

  return iterator(to_add);
}

template <class T>
void dslist<T>::copy_list (const dslist<T>& old) {
  // copy the contents of old dslist into this dslist

  // start with the head
  this->head_ = new Node<T>(old.head_->value);
  Node<T>* this_prev = head_;

  for (iterator itr = ++old.begin(); itr != old.end(); ++itr) {
    Node<T>* to_add;
    to_add = new Node<T>(itr.ptr_->value);
    to_add->prev_ = this_prev;
    this_prev->next_ =  to_add;

    if ( itr.ptr_ == old.tail_ ) { // if this is the tail,
      this->tail_ = to_add;
    }

    this_prev = to_add;
  }
  this->size_ = old.size_;

}

template <class T>
void dslist<T>::destroy_list () {
  // should delete all components within the list and return memory

  // Step 1: delete all nodes in the list (dynamically deallocate)
  for (iterator itr = this->begin(); itr != this->end(); itr) {
    iterator current = itr++;
    delete current.ptr_;
  }

  // that's it
}

#endif
