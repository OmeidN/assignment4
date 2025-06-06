// Created by Frank M. Carrano and Timothy M. Henry.
// Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file Node.h 
    Listing 4-1 */

#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node

public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(Node<ItemType>* nextNodePtr);
   ItemType getItem() const;
   Node<ItemType>* getNext() const;
}; // end Node

// Inline template method definitions

template<class ItemType>
Node<ItemType>::Node() : next(nullptr) { }

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr) { }

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
                item(anItem), next(nextNodePtr) { }

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
   item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
   next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
   return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
   return next;
}

#endif // NODE_
