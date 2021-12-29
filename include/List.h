#ifndef COURSEWORK_INCLUDE_LIST_H_
#define COURSEWORK_INCLUDE_LIST_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

#define START_LENGTH 2                                          // Начальная длина певрого массива
#define FACTOR 2                                                // Множитель каждого следующего массива

template<typename T>
struct Node {
  T **field;
  Node *next;
  unsigned int length;                                          // Максимальная  длина массива
  unsigned int c_size;                                          // Текущая длина массива
  explicit Node(unsigned int _length);
  Node(T *_field, unsigned int _length);
  ~Node();
};

template<typename T>
class List {
 public:
  List();
  ~List();

  void insert(T *_field, unsigned int pos);                     // Вставка по позиции в массив
  void add(T *_field);                                          // Добавление нового элемента в свободное место
  void remove(unsigned int pos);                                // Удаление элемента
  void sort();                                                  // Сортировка
  void balance();                                               // Балансировка

  void add_arr();                                               // Добавление ноды
  void insert_arr(unsigned int pos);                            // Вставка массива по позиции
  void remove_arr(unsigned int pos);                            // Удаление массива полностью как ноду списка
  void read_bin(std::fstream &in);                              // Чтение из файла
  void write_bin(std::fstream &out);                            // Запись в файл
  T *get_elem(unsigned int list_num, unsigned int arr_pos);     // Геттер элемента

  template<class V>
  friend std::istream &operator>>(std::istream &in, List<V> &list);
  template<class V>
  friend std::ostream &operator<<(std::ostream &out, List<V> &list);

 private:
  Node<T> *head;
  unsigned int size;
  bool is_empty();

  unsigned int get_arr_size(unsigned int num);
  unsigned int get_arr_length(unsigned int num);
  unsigned int get_non_empty_nodes();
  unsigned int get_elem_count();
  unsigned int get_list_size();
  Node<T> *get_node(unsigned int num);
};

template<class V>
istream &operator>>(istream &in, List<V> &list) {
  V *a = new V;
  in >> *a;
  list.add(a);
  delete a;
  return in;
}

template<class V>
ostream &operator<<(ostream &out, List<V> &list) {
  Node<V> *tmp = list.head;
  for (int i = 0; i < list.size; ++i) {
    out << tmp->c_size << " " << tmp->length << "| ";
    for (int j = 0; j < tmp->c_size; ++j) {
      out << *(tmp->field[j]) << " ";
    }
    tmp = tmp->next;
    out << "\n";
  }
  return out;
}

#endif //COURSEWORK_INCLUDE_LIST_H_
