#include <stdexcept>
#include "Single_Linked_List.h"
using namespace std;

// Constructor
template <class T>
Single_Linked_List<T>::Single_Linked_List() {
  head = tail = nullptr;
  num_items = 0;
}

// Destructor
template <class T>
Single_Linked_List<T>::~Single_Linked_List() {
  ListNode<T>* tmp;
  // Advance through the list, deleting each node
  do {
    tmp = head;
    head = head->getNext();
    delete tmp;
  } while (head != nullptr);
}

template <class T>
void Single_Linked_List<T>::push_front(T data) {
  ListNode<T>* newNode = new ListNode<T>(data);

  if (head == nullptr) {
    head = tail = newNode;
  } else {
    newNode->setNext(head);
    head = newNode;
  }
  num_items++;
}

template <class T>
void Single_Linked_List<T>::push_back(T data) {
  ListNode<T>* newNode = new ListNode<T>(data);

  if (head == nullptr) {
    head = tail = newNode;
  } else {
    tail->setNext(newNode);
    tail = newNode;
  }
  num_items++;
}

template <class T>
T Single_Linked_List<T>::pop_front() {
  // Check if list is empty
  if (head == nullptr) {
    throw runtime_error("Single_Linked_List is empty, cannot pop");
  }

  // Save the first value of the list, and then delete it
  T val = head->getData();
  ListNode<T>* tmp = head;
  head = head->getNext();
  delete tmp;
  num_items--;
  return val;
}


// TODO: you need a double linked list to pop back in constant time. Otherwise, it is linear.
template <class T>
T Single_Linked_List<T>::pop_back() {
  // Check if list is empty
  if (head == nullptr) {
    throw runtime_error("Single_Linked_List is empty, cannot pop");
  }

  // Save the first value of the list, and then delete it
  T val = tail->getData();
  ListNode<T>* tmp = head;
  head = head->getNext();
  delete tmp;
  num_items--;
  return val;
}

template <class T>
T Single_Linked_List<T>::front() const {
  return head;
}

template <class T>
T Single_Linked_List<T>::back() const {
  return tail;
}

template <class T>
bool Single_Linked_List<T>::empty() const {
  return num_items == 0;
}

template <class T>
void Single_Linked_List<T>::insert(size_t index, const T& item) {
  ListNode<T>* newNode = new ListNode<T>(item);
  if (index == 0) {
    newNode->setNext(head);
  } else {
    ListNode<T>* walker = head;
    for (size_t i = 0; (i < index && i < num_items); i++) {
      walker = walker->next;
    }
    newNode->setNext(walker->next);
    walker->setNext(newNode);

    if (index > num_items - 1) {
      tail = newNode;
    }
  }
}
