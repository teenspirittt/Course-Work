#ifndef COURSEWORK_INCLUDE_LIST_H_
#define COURSEWORK_INCLUDE_LIST_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

#define START_LENGTH 2                                  // Начальная длина певрого массива
#define FACTOR 2                                        // Множитель каждого следующего массива

// TODO
//// Поменять название переменных и функций
//// Сделать remove_from_arr(), sort(), balance(), load_from_bin()
//// Сделать настройки меню(Русский язык, man, info)
//// Сделать пару тестов

template<typename T>
struct Node {
  T **field;
  Node *next;
  unsigned int length;                          //максимальная  длина массива
  unsigned int c_size;                          // current длина массива
  explicit Node(unsigned int _length);
  Node(T *_field, unsigned int _length);
  ~Node();
};

template<typename T>
class List {
 public:
  List();
  // List(T *_field);
  // List(T &_field);
  ~List();

  void insert_in_array(T *_field, unsigned int pos);    // Вставка по позиции в массив
  void add(T *_field);                                  // Добавление нового элемента в свободное место
  void add_array();                                     // Добавление ноды
  void insert_array(unsigned int pos);                 // Вставка массива по позиции
  void remove(unsigned int pos);                        // Удаление массива полностью как ноду списка
  void remove_from_array(unsigned int pos);             // "Прицельное" удаление
  int get_list_size();                                       // Вывод размера списка
  void sort();
  void balance();
  void load_from_bin(std::fstream &in);
  void load_to_bin(std::fstream &out);
  T *get_elem(unsigned int list_num, unsigned int arr_pos);
  // TODO
  //T &operator[](const unsigned int num);

  template<class V>
  friend std::istream &operator>>(std::istream &in, List<V> &list);
  template<class V>
  friend std::ostream &operator<<(std::ostream &out, List<V> &list);

 private:
  Node<T> *head;
  bool is_empty();
  unsigned int size;                                 // длина списка
  unsigned int get_arr_size(unsigned int num);
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
    for (int j = 0; j < tmp->c_size; ++j) {
      out << *(tmp->field[j]) << " ";
    }
    tmp = tmp->next;
    out << "\n";
  }
  return out;
}

#endif //COURSEWORK_INCLUDE_LIST_H_
