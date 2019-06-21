//
// Created by mfbut on 2/13/2019.
//

#ifndef LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H

template<typename T>
class ReverseDoublyLinkedListIterator {
 public:
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

  ReverseDoublyLinkedListIterator(DoubleLinkedNode<T>* node) {

    (*this).node = node;

  }

  //copy constructor
  ReverseDoublyLinkedListIterator(const ReverseDoublyLinkedListIterator& orig) {

      this->node = orig.node;

  }

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)

  bool operator==(const ReverseDoublyLinkedListIterator<T>& rhs) const {

    return this->node == rhs.node;


  }

  bool operator!=(ReverseDoublyLinkedListIterator<T>& rhs) const {

      return this->node != rhs.node;

  }

  operator bool() const {

      return this->node !=nullptr;

  }

  ReverseDoublyLinkedListIterator<T>& operator++() { //pre

      this->node = this->node->findPrevious();

      return *this;
  }
  const ReverseDoublyLinkedListIterator<T> operator++(int) { //post

      auto tent = *this;

      this->node = this->node->findPrevious();

      return tent;
  }

  ReverseDoublyLinkedListIterator<T>& operator--() { //pre

    this->node = this->node->findNext();

    return *this;
  }
  const ReverseDoublyLinkedListIterator<T> operator--(int) { //post

    auto tent = *this;

    this->node = this->node->findNext();

    return tent;
  }

  const T& operator*() const {

    return this->node->findValue();

  }

  T& operator*() {

    return this->node->findValue();
  }

  T* getNode() {

    return this->node;
  }
  
private:

    DoubleLinkedNode<T>* node;

};

#endif //LINKEDLIST_GENERICREVERSEDOUBLYLINKEDLISTITERATOR_H
