#pragma once
using namespace std;

template <class T>
class ListNode {
private:
  ListNode* next;
  T data;
public:
  ListNode(T data);
  T getData();
  ListNode* getNext();
  void setNext(ListNode* next);
};

template <class T>
class Single_Linked_List {
private:
  ListNode<T>* head;
  ListNode<T>* tail;
  size_t num_items;
public:
  Single_Linked_List();
  ~Single_Linked_List();
  void push_front(T data);
  void push_back(T data);
  T pop_front();
  T pop_back();
  T front() const;
  T back() const;
  bool empty() const;
  void insert(size_t index, const T& item);
  bool remove(size_t index);
  size_t find(const T& item) const;
};
