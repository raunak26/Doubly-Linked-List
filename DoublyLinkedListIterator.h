//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H

template<typename T>
class DoublyLinkedListIterator {
  public:
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

  DoublyLinkedListIterator(DoubleLinkedNode<T>* node) {

      this->node = node;
  }
  //copy constructor
  DoublyLinkedListIterator(const DoublyLinkedListIterator& orig) {

      this->node = orig.node;
  }
  
  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const DoublyLinkedListIterator<T>& rhs) const {

      return this->node == rhs.node;

  }

  bool operator!=(const DoublyLinkedListIterator<T>& rhs) const {

      return this->node != rhs.node;
  }

  operator bool() const {

      return this->node !=nullptr;
  }

  DoublyLinkedListIterator<T>& operator++() { //pre

      this->node = this->node->findNext();

      return *this;
  }

  const DoublyLinkedListIterator<T> operator++(int) { //post

      auto tent = *this;

      this->node = this->node->findNext();

      return tent;
  }

  DoublyLinkedListIterator<T>& operator--() { //pre
    this->node = this->node->findPrevious();
    return *this;
  }
  const DoublyLinkedListIterator<T> operator--(int) { //post

    auto tent = *this;

    this->node = this->node->findPrevious();

    return tent;
  }

  const T& operator*() const {

      return this->node->findValue();
  }

  T& operator*() {

      return this->node->findValue();
  }

  DoubleLinkedNode<T>* findNode() {

      return this->node;
  }

private:

    DoubleLinkedNode<T>* node;

};

#endif //LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H

// done
