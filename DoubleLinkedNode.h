//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>

template<typename T>
class DoubleLinkedNode {

	private:
        T value;
		DoubleLinkedNode<T> *previous;
		DoubleLinkedNode<T> *next;


	public:
		DoubleLinkedNode(T value) {
			this->value = value;

            this->next = nullptr;

			this->previous = nullptr;

		}

        DoubleLinkedNode<T> *findNext() {
            return this->next;
        }

		DoubleLinkedNode<T> *findPrevious() {
			return this->previous;
		}

        T& findValue() {
            return this->value;
        }

		void assignNext(DoubleLinkedNode<T> *node) {
			next = node;
		}


        void assignPrevious(DoubleLinkedNode<T> *node) {
            previous = node;
        }
};

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
