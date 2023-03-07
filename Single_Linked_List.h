#pragma once
#include <cstddef>
#include <stdexcept>
using namespace std;

template <class T>
struct ListNode {
  ListNode* next;
  T data;
};

template <class T>
class Single_Linked_List {
private:
  ListNode<T>* head;
  ListNode<T>* tail;
  size_t num_items;
public:
  // Constructor
  Single_Linked_List() {
    head = tail = nullptr;
    num_items = 0;
  }

  // Destructor
  ~Single_Linked_List() {
    ListNode<T>* tmp;
    // Advance through the list, deleting each node
    while (head != nullptr) {
      tmp = head;
      head = head->next;
      delete tmp;
    }
  }
  
  void push_front(T data) {
    ListNode<T>* newNode = new ListNode<T>;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
      // Pushing an empty list sets head and tail
      head = tail = newNode;
    } else {
      // Push to the front
      newNode->next = head;
      head = newNode;
    }
    num_items++;
  }
  
  void push_back(T data) {
    ListNode<T>* newNode = new ListNode<T>;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
      // Pushing an empty list sets head and tail
      head = tail = newNode;
    } else {
      // push to the back
      tail->next = newNode;
      tail = newNode;
    }
    num_items++;
  }
  
  T pop_front() {
    // Check if list is empty
    if (head == nullptr) {
      throw runtime_error("Single_Linked_List is empty, cannot pop");
    }

    // Save the first value of the list, and then delete it
    T val = head->data;
    if (num_items == 1) {
      // Empty the list properly
      delete head;
      head = tail = nullptr;
    } else {
      // Pop off the head
      ListNode<T>* tmp = head;
      head = head->next;
      delete tmp;
    }
    num_items--;
    return val;
  }
  
  T pop_back() {
    // Check if list is empty
    if (head == nullptr) {
      throw runtime_error("Single_Linked_List is empty, cannot pop");
    }

    T val = tail->data;
    if (num_items == 1) {
      // empty the list properly
      delete head;
      head = tail = nullptr;
    } else {
      // walk to the penultimate node
      ListNode<T>* walker = head;
      while (walker->next != tail) {
	walker = walker->next;
      }
      // delete the last node and set the penultimate node to tail
      delete tail;
      tail = walker;
      tail->next = nullptr;
    }
    num_items--;
    return val;
  }
  
  T front() const {
    return head->data;
  }
  
  T back() const {
    return tail->data;
  }

  bool empty() const {
    return num_items == 0;
  }
  
  void insert(size_t index, const T& item) {
    ListNode<T>* newNode = new ListNode<T>;
    newNode->data = item;
    newNode->next = nullptr;
    
    if (index == 0) {
      // insert at beginning
      newNode->next = head;
      head = newNode;
      
      if (tail == nullptr) {
	// if inserting in an empty list
	tail = head;
      }
    } else if (index >= num_items) {
      // insert at end
      tail->next = newNode;
      tail = newNode;
      
      if (head == nullptr) {
	// if inserting in an empty list
        head = tail;
      }
    } else {
      // walk through the list until you have a pointer to the right position
      ListNode<T>* walker = head;
      for (size_t i = 0; i < index - 1; i++) {
	walker = walker->next;
      }

      // Insert the node at that position
      newNode->next = walker->next;
      walker->next = newNode;
    }
    num_items++;
  }
  
  bool remove(size_t index) {
    // Two pointers walk the list to properly delete
    ListNode<T>* prev = head;
    ListNode<T>* next = prev->next;
    
    if (index >= num_items) {
      // Fail the removal if the index is past the number of items
      return false;
    }
    if (index == 0) {
      // delete from front
      head = next;
      delete prev;
    } else {
      // if deleting from anywhere else, walk the next pointer to that point
      for (size_t i = 1; i < index - 1; i++) {
        prev = prev->next;
	next = next->next;
      }

      // Delete that node
      prev->next = next->next;
      delete next;
      if (prev->next == nullptr) {
	// Make sure the tail is clean
	tail = prev->next;
      }
    }
    num_items--;
    return true;
  }
  
  size_t find(const T& item) const {
    ListNode<T>* walker = head;
    for (size_t i = 0; i < num_items; i++) {
      if (walker->data == item) {
	return i;
      }
      walker = walker->next;
    }
    return num_items;
  }
};
