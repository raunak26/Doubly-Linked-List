//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoubleLinkedNode.h"
#include "DoublyLinkedListIterator.h"
#include "ReverseDoublyLinkedListIterator.h"
#include "ConstDoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedListIterator.h"

template<typename T>
class DoublyLinkedList {
 public:
  using Node_Ptr = DoubleLinkedNode<T>*;

  using iterator =  DoublyLinkedListIterator<T>;
  using const_iterator =  ConstDoublyLinkedListIterator<T>;
  using reverse_iterator = ReverseDoublyLinkedListIterator<T>;
  using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>;

  explicit DoublyLinkedList(const std::vector<T>& values) {
      len = 0;
      head = nullptr;
      tail = nullptr;
      for (const auto& value : values) {
        push_back(value);
      }
  };

  DoublyLinkedList() {
      len = 0;
    head = nullptr;
    tail = nullptr;

  };

  //virtual ~DoublyLinkedList();

  DoubleLinkedNode<T> tailReturn() {
        return tail;
    }

  DoubleLinkedNode<T> headReturn() {
    return head;
  }


  void tailReassign(const DoubleLinkedNode<T> node) {
    tail = node;
  }

  void clear() {
    for (int i = 0; i < this->size(); i++) {

        auto temp = head;

      delete head;

      head = temp->findNext();
    }
    len = 0;
  }

  const T& front() const {
    return head->findValue();
  }
  T& front() {
    return head->findValue();
  }

  const T& back() const {
    return tail->findValue();
  }
  T& back() {
    return tail->findValue();
  }

  void push_front(const T& value) {
    DoubleLinkedNode<T>* node = new DoubleLinkedNode<T>(value);
    if(head == nullptr) {
        head = node;
        tail = node;
    }
    else {
      head->assignPrevious(node);

      node->assignNext(head);

      head = node;
    }
    len++;
  }

  void push_back(const T& value) {
    DoubleLinkedNode<T>* node = new DoubleLinkedNode<T>(value);
    if(head == nullptr) {

        tail = node;

        head = node;

    }
    else if (this->size() == 1) {
        tail = node;

        head->assignNext(tail);

        tail->assignPrevious(head);
    }
    else {

        tail->assignNext(node);

      node->assignPrevious(tail);

      tail = node;
    }

    len++;
    //delete node;
  }

  bool empty() const {
    if(head == nullptr && tail == nullptr) {
      return true;
    }
    else {

        return false;
    }
  }

  int size() const {

      return len;
  }

  void lenInc() {
    len++;
  }

  const_iterator begin() const {
    return ConstDoublyLinkedListIterator<T>(head);
  }
  const_iterator end() const {
    return ConstDoublyLinkedListIterator<T>(nullptr);
  }

  iterator begin() {
    return DoublyLinkedListIterator<T>(head);
  }
  iterator end() {
    return DoublyLinkedListIterator<T>(nullptr);
  }

  const_reverse_iterator crbegin() const {
    return ConstReverseDoublyLinkedListIterator<T>(tail);
  }
  const_reverse_iterator crend() const {
    return ConstReverseDoublyLinkedListIterator<T>(nullptr);
  }

  reverse_iterator rbegin() {
    return ReverseDoublyLinkedListIterator<T>(tail);
  }
  reverse_iterator rend() {
    return ReverseDoublyLinkedListIterator<T>(nullptr);
  }

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value) {

      DoubleLinkedNode<T>* tent = new DoubleLinkedNode<T>(value);

    if (position.findNode() == head) {
      push_front(value);
    }
    else if (position.findNode() == nullptr) {

        push_back(value);
    }
    else {

        position.findNode()->findPrevious()->assignNext(tent);

        tent->assignPrevious(position.findNode()->findPrevious());

        tent->assignNext(position.findNode());

        position.findNode()->assignPrevious(tent);

        len++;
    }
  }

  void erase(iterator& position) {

      if (position.findNode() == head) {

          head = head->findNext();

          if (head != nullptr) {

              head->assignPrevious(nullptr);

          }

          else {

              tail = nullptr;

          }

      }

      else if (position.findNode() == tail) {

          tail = tail->findPrevious();

          tail->assignNext(nullptr);

      }

      else {

          position.findNode()->findNext()->assignPrevious(position.findNode()->findPrevious());

          position.findNode()->findPrevious()->assignNext(position.findNode()->findNext());


      }

      len--;

  }

 private:

    Node_Ptr head;

  Node_Ptr tail;

  int len;

};

//write to the stream each element in the list in order
//with a space in between them
template<typename T>

std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList) {

  for (auto it = doublyLinkedList.begin(); it != doublyLinkedList.back(); it++) {

    if (it == doublyLinkedList.back()) {

      out << it;

    }

    out << it << " ";


  }

  return out;

}

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encontered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList) {

    while(in) {

        T tent;

        in >> tent;

        if (tent == '\n') {

            break;

        }

        DoubleLinkedNode<T>* node = new DoubleLinkedNode<T>(tent);

        node->assignPrevious(doublyLinkedList.findTail());

        doublyLinkedList.findTail()->assignNext(node);

        doublyLinkedList.findTail() = &node;

        doublyLinkedList->lenInc();

    }

    return in;

}


#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
