#ifndef COURSEWORK_SRC_LIST_INL_
#define COURSEWORK_SRC_LIST_INL_

#include <iostream>

#include "List.h"

template <typename T>
Node<T>::Node(T *_field, unsigned int _length) {
  field = new T *[_length];
  next = nullptr;
  length = _length;
  field[0] = new T(*_field);
  c_size = 1;
}

template <typename T>
Node<T>::Node(unsigned int _length) {
  field = new T *[_length];
  next = nullptr;
  length = _length;
  c_size = 1;
}

template <typename T>
Node<T>::~Node() {
  for (int i = 0; i < c_size; ++i) {
    delete field[i];
  }
  delete[] field;
}

template <typename T>
List<T>::List() {
  head = nullptr;
  size = 0;
}

template <typename T>
List<T>::~List() {
  while (size != 0) {
    Node<T> *tmp = head->next;
    delete head;
    head = tmp;
    size--;
  }
}

template <typename T>
int List<T>::get_size() {
  return size;
}

template <typename T>
bool List<T>::is_empty() {
  return head == nullptr;
}

template <typename T>
void List<T>::remove(unsigned int pos) {
  if (pos == 0) {
    Node<T> *tmp1 = head->next;
    delete head;
    head = tmp1;
  } else {
    Node<T> *tmp1 = head;
    for (int i = 0; i < pos - 1; ++i) tmp1 = tmp1->next;
    Node<T> *tmp2 = tmp1->next;
    tmp1->next = tmp1->next->next;
    delete tmp2;
  }
  size--;
}

template <typename T>
void List<T>::add(T *_field) {
  if (is_empty()) {
    head = new Node<T>(_field, START_LENGTH);
    size++;
  } else {
    Node<T> *tmp = head;
    Node<T> *tmp2;
    while (tmp != nullptr && tmp->c_size == tmp->length) {
      tmp2 = tmp;
      tmp = tmp->next;
    }
    if (tmp == nullptr) {
      tmp = new Node<T>(_field, tmp2->length * FACTOR);
      tmp2->next = tmp;
      size++;
    } else {
      tmp->field[tmp->c_size] = new T(*_field);
      tmp->c_size++;
    }
  }
}

template <typename T>
void List<T>::add_array() {
  if (is_empty()) {
    head = new Node<T>(START_LENGTH);
  } else {
    Node<T> *tmp = head;
    while (tmp->next != nullptr) {
      tmp = tmp->next;
    }
    tmp->next = new Node<T>(tmp->length * FACTOR);
  }
}

template <typename T>
void List<T>::insert_array(T *_field, unsigned int pos) {
  if (pos > size) {
    // TODO
    std::cout << "AAAAAAAAAAAAAAAAAA!";
  }
  if (pos == 0) {
    Node<T> *tmp = head;
    head = new Node<T>;
    head->next = tmp;
  } else {
    Node<T> *tmp = head;
    for (int i = 0; i < pos; ++i) {
      tmp = tmp->next;
    }
    Node<T> *tmp2 = tmp->next;
    tmp->next = new Node<T>;
    tmp->next->next = tmp2;
  }
  size++;
}

template <typename T>
T *List<T>::get(unsigned int list_num, unsigned int arr_pos) {
  if (is_empty()) {
    // TODO
    std::cout << "AAAAAAAAAAAAAAAAA!!!\n";
  }
  Node<T> *tmp = head;
  for (int i = 0; i < list_num; ++i) {
    tmp = tmp->next;
  }
  return tmp->field[arr_pos];
}

template <class V>
std::istream &operator>>(std::istream &in, List<V> &list) {
  V *a = new V;
  in >> *a;
  list.add(a);
  delete a;
  return in;
}

template <class V>
std::ostream &operator<<(std::ostream &out, List<V> &list) {
  Node<V> *tmp = list.head;
  for (int i = 0; i < list.size; ++i) {
    for (int j = 0; j < tmp->c_size; ++j) {
      out << *(tmp->field[j]) << " ";
    }
    tmp = tmp->next;
    out << "\n";
  }
  return out;
}

template <typename T>
void List<T>::load_to_bin(std::fstream &out) {
  if (out.is_open()) {
    Node<T> *tmp = head;
    for (int i = 0; i < size; ++i) {
      out.write((char *)&(tmp->c_size), sizeof(unsigned int));
      for (int j = 0; j < tmp->c_size; ++j) {
        out.write((char *)tmp->field[j], sizeof(T));
      }
      tmp = tmp->next;
    }
  }
}

template <typename T>
void List<T>::load_from_bin(std::fstream &in) {
  if (in.is_open()) {
    while (head) {
      remove(0);
    }
    Node<T> *tmp;
    if (in.peek() != EOF) {
      head = tmp = new Node<T>;
      size = 1;
    }
    T *tmp2 = new T;
    unsigned int sz;
    while (in.peek() != EOF) {
      in.read((char *)&sz, sizeof(unsigned int));
      if (sz) {
        in.read((char *)tmp, sizeof(unsigned int));
      }
    }
  }
}

#endif  // COURSEWORK_SRC_LIST_INL_

/*
template<typename T>
Node<T> *List<T>::operator[](const int d) {
  if (is_empty())
    return nullptr;
  Node<T> *p = head;
  for (int i = 0; i < d; ++i) {
    p = p->next;
    if (!p)
      return nullptr;
  }
  return p;
}
*/
