#ifndef COURSEWORK_INCLUDE_LIST_H_
#define COURSEWORK_INCLUDE_LIST_H_

#include <fstream>
#include <iostream>

#define START_LENGTH 2  // Начальная длина певрого массива
#define FACTOR 2  // Множитель каждого следующего массива

template <typename T>
struct Node {
  T **field;
  Node *next;
  unsigned int length;  //максималььная  длина массива
  unsigned int c_size;  // current длина массива
  explicit Node(unsigned int _length);
  Node(T *_field, unsigned int _length);
  ~Node();
};

template <typename T>
class List {
 public:
  List();
  // List(T *_field);
  // List(T &_field);
  ~List();

  void insert_in_array(T *_field,
                       unsigned int pos);  // Вставка по позиции в массив
  void add(T *_field);  // Добавление нового элемента в свободное место
  void add_array();     // Добавление ноды
  void insert_array(T *_field, unsigned int pos);  // Вставка массива по позиции
  void remove(unsigned int pos);  // Удаление массива полностью как ноду списка
  void remove_from_array(unsigned int pos);  // "Прицельное" удаление
  int get_size();                            // Вывод списка
  void sort();
  void balance();
  void load_from_bin(std::fstream &in);
  void load_to_bin(std::fstream &out);
  T *get(unsigned int list_num, unsigned int arr_pos);
  // TODO
  // Node<T> *operator[](const int d);

  template <class V>
  friend std::istream &operator>>(std::istream &in, List<V> &list);
  template <class V>
  friend std::ostream &operator<<(std::ostream &out, List<V> &list);

 private:
  Node<T> *head;
  bool is_empty();
  unsigned int size;  // длина списка
};

#include "List.inl"

#endif  // COURSEWORK_INCLUDE_LIST_H_
