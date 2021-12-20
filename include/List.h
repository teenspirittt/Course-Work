#ifndef COURSEWORK_INCLUDE_LIST_H_
#define COURSEWORK_INCLUDE_LIST_H_

#include "Node.h"

template<typename T>
class List {
 public:
  List()
      : first(nullptr), last(nullptr), size(0) {};
  ~List();
  void push_front(T *field);
  void push(T *a, uint pos);
  void push_back(T *_field);
  void pop_front();
  void pop(uint index);
  void pop_back();
  Node *find(T *_field);
  void pop();
  void pop(uint pos);
  void show();
  int count();
  Node &operator[](const int d);
  bool is_empty() { return first == nullptr }
 private:

  Node *first;
  Node *last;
  uint size;
};

#include "../src/List.inl"

#endif //COURSEWORK_INCLUDE_LIST_H_
