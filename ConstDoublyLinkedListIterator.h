//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H

template<typename T>
class ConstDoublyLinkedListIterator {
  public:
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods


  ConstDoublyLinkedListIterator(DoubleLinkedNode<T>* node) {
    this->node = node;

  }


  ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator& orig) {
    this->node = orig.node;

  }

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ConstDoublyLinkedListIterator<T>& rhs) const {

      return this->node == rhs.node;

  }

  bool operator!=(const ConstDoublyLinkedListIterator<T>& rhs) const {

      return this->node != rhs.node;

  }


  operator bool() const {

    return !!this->node;

  }


  ConstDoublyLinkedListIterator<T>& operator++() { //pre

    this->node = this->node->findNext();

    return *this;

  }

  const ConstDoublyLinkedListIterator<T> operator++(int) { //post

    auto temp = *this;

    this->node = this->node->findNext();

    return temp;

  }

  ConstDoublyLinkedListIterator<T>& operator--() {

    this->node = this->node->findPrevious();

    return *this;

  }

  const ConstDoublyLinkedListIterator<T> operator--(int) {

    auto temp = *this;

    this->node = this->node->findPrevious();

    return temp;

  }


  const T& operator*() const {

    return this->node->findValue();

  }



  T* findNode() {

    return this->node->findValue();

  }


private:

    DoubleLinkedNode<T>* node;


};

#endif //TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
