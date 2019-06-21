//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H

template<typename T>
class ConstReverseDoublyLinkedListIterator {
public:
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

  ConstReverseDoublyLinkedListIterator(DoubleLinkedNode<T>* node) {
    this->node = node;
  }
  //copy constructor
  ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator& orig) {
    this->node = orig.node;
  }

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ConstReverseDoublyLinkedListIterator<T>& rhs) const {
    return this->node == rhs.node;
  }

  bool operator!=(ConstReverseDoublyLinkedListIterator<T>& rhs) const {
    return this->node != rhs.node;
  }

  operator bool() const {
    return !!this->node;
  }

  ConstReverseDoublyLinkedListIterator<T>& operator++() { //pre
    this->node = this->node->findPrevious();
    return *this;
  }
  const ConstReverseDoublyLinkedListIterator<T> operator++(int) { //post
    auto temp = *this;
    this->node = this->node->findPrevious();
    return temp;
  }

  ConstReverseDoublyLinkedListIterator<T>& operator--() { //pre
    this->node = this->node->findNext();
    return *this;
  }
  const ConstReverseDoublyLinkedListIterator<T> operator--(int) { //post
    auto temp = *this;
    this->node = this->node->findNext();
    return temp;
  }

  const T& operator*() const {
    return this->node->findValue();
  }

  T* findNode() {
    return this->node;
  }

private:
  DoubleLinkedNode<T>* node;

};

#endif //TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
