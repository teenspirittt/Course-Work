#ifndef MATRIXES_SRC_UNILISTS_INL_
#define MATRIXES_SRC_UNILISTS_INL_

#include <iostream>
#include "../include/List.h"

template<typename T>
void List<T>::push_back(T *_field) {
  Node *p = new Node(_field);
  if (is_empty()) {
    first = p;
    last = p;
    return;
  }
  last->next = p;
  last = p;
  size++;
}

template<typename T>
Node *List<T>::find(T *_field) {
  Node *p = first;
  while (p && p->field != _field)
    p = p->next;

  return (p && p->field == _field) ? p : nullptr;
}

template<typename T>
Node &List<T>::operator[](const int d) {
  if (is_empty())
    return nullptr;
  Node *p = first;
  for (int i = 0; i < d; ++i) {
    p = p->next;
    if (!p)
      return nullptr;
  }
  return p;
}
template<typename T>
void List<T>::pop_back() {
  if (is_empty()) return;
  if (first == last) {
    remove_first();
    return;
  }
  Node *p = first;
  while (p->next != last) p = p->next;
  p->next = nullptr;
  delete last;
  last = p;
  size--;
}
template<typename T>
void List<T>::pop_front() {
  if (is_empty()) return;
  Node *p = first;
  first = p->next;
  delete p;
  size--;
}
template<typename T>
void List<T>::pop(uint index) {

}

#endif // MATRIXES_SRC_UNILISTS_INL_
