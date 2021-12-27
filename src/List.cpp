
#include "../include/List.h"

template<typename T>
Node<T>::Node(T *_field, unsigned int _length) {
  field = new T *[_length];
  next = nullptr;
  length = _length;
  field[0] = _field;
  c_size = 1;
}

template<typename T>
Node<T>::Node(unsigned int _length) {
  field = new T *[_length];
  next = nullptr;
  length = _length;
  c_size = 0;
}

template<typename T>
Node<T>::~Node() {
  for (int i = 0; i < c_size; ++i) {
    delete field[i];
  }
  delete[] field;
}

template<typename T>
List<T>::List() {
  head = nullptr;
  size = 0;
}

template<typename T>
List<T>::~List() {
  while (size != 0) {
    Node<T> *tmp = head->next;
    delete head;
    head = tmp;
    size--;
  }
}

template<typename T>
int List<T>::get_list_size() {
  return size;
}

template<typename T>
unsigned int List<T>::get_arr_size(unsigned int num) {
  return get_node(num)->c_size;
}

template<typename T>
Node<T> *List<T>::get_node(unsigned int num) {
  Node<T> *tmp = head;
  for (unsigned int i = 0; i < num && tmp; ++i) {
    tmp = tmp->next;
  }
  return tmp;
}

template<typename T>
bool List<T>::is_empty() {
  return head == nullptr;
}

template<typename T>
void List<T>::remove(unsigned int pos) {
  if (pos == 0) {
    Node<T> *tmp1 = head->next;
    delete head;
    head = tmp1;
  } else {
    Node<T> *tmp1 = head;
    for (int i = 0; i < pos - 1; ++i)
      tmp1 = tmp1->next;
    Node<T> *tmp2 = tmp1->next;
    tmp1->next = tmp1->next->next;
    delete tmp2;
  }
  size--;
}

template<typename T>
void List<T>::remove_from_array(unsigned int pos) {
  Node<T> *tmp;
  unsigned int sz;
  unsigned int arr_num = 0;
  for (unsigned int i = 0; i < size && pos >= get_arr_size(i); ++i) {
    pos -= get_arr_size(i);
    arr_num++;
  }
  tmp = get_node(arr_num);
  for (unsigned int i = arr_num; i < size; ++i) {
    for (unsigned int j = pos; j < (tmp->c_size - 1) && (tmp->c_size != 0); ++j) {
      tmp->field[j] = tmp->field[j + 1];
      sz = j;
    }
    if ((pos == tmp->c_size - 1) && (tmp->next != nullptr)) {
      sz = tmp->c_size - 1;
      tmp->field[sz] = tmp->next->field[0];
    }
    if (sz < tmp->length && tmp->next != nullptr) {
      tmp->field[sz + 1] = tmp->next->field[0];
      tmp = tmp->next;
    }
    if (tmp->next == nullptr) {
      tmp->c_size--;
    }
    pos = 0;
  }
}

template<typename T>
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
  size++;
}

template<typename T>
void List<T>::insert_array(unsigned int pos) {
  if (pos > size) {
    // TODO
    cout << "AAAAAAAAAAAAAAAAAA!";
  }
  if (pos == 0) {
    Node<T> *tmp = head;
    head = new Node<T>(START_LENGTH);
    head->next = tmp;
  } else {
    Node<T> *tmp = head;
    for (int i = 0; i < pos - 1; ++i) {
      tmp = tmp->next;
    }
    Node<T> *tmp2 = tmp->next;
    tmp->next = new Node<T>(tmp->length * FACTOR);
    tmp->next->next = tmp2;
  }
  size++;
}

template<typename T>
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
      tmp->field[tmp->c_size] = _field;
      tmp->c_size++;
    }
  }
}

template<typename T>
void List<T>::insert_in_array(T *_field, unsigned int pos) {
  Node<T> *tmp = head;
  Node<T> *tmp2;
  unsigned int arr_num = 0;
  for (unsigned int i = 0; i < size && pos >= get_arr_size(i); ++i) {
    pos -= get_arr_size(i);
    arr_num++;
  }
  if (get_arr_size(arr_num) == tmp->length) {
    while (tmp != nullptr && tmp->c_size == tmp->length) {
      tmp2 = tmp;
      tmp = tmp->next;
    }
    if (tmp == nullptr) {
      tmp = new Node<T>(tmp2->length * FACTOR);
      tmp2->next = tmp;
      size++;
    }
    tmp = get_node(arr_num);
    if (tmp->c_size < tmp->length - 1) {
      for (int i = tmp->c_size; i > pos; --i) {
        tmp->field[i] = tmp->field[i - 1];
      }
      tmp->field[pos] = _field;
    } else {
      T *last_el = tmp->field[tmp->c_size - 1];
      for (int i = tmp->c_size - 1; i > pos; --i) {
        tmp->field[i] = tmp->field[i - 1];
      }
      tmp->field[pos] = _field;
      tmp = tmp->next;
      while (tmp->c_size == tmp->length) {
        T *last_el2 = tmp->field[tmp->c_size - 1];
        for (int i = tmp->c_size - 1; i > 0; --i) {
          tmp->field[i] = tmp->field[i - 1];
        }
        tmp->field[0] = last_el;
        last_el = last_el2;
        tmp = tmp->next;
      }
      for (int i = tmp->c_size; i > 0; --i) {
        tmp->field[i] = tmp->field[i - 1];
      }
      tmp->field[0] = last_el;
      tmp->c_size++;
    }
  }
}

template<typename T>
void List<T>::load_to_bin(fstream &out) {
  if (out.is_open()) {
    Node<T> *tmp = head;
    for (int i = 0; i < size; ++i) {
      out.write((char *) &(tmp->c_size), sizeof(unsigned int));
      for (int j = 0; j < tmp->c_size; ++j) {
        out.write((char *) tmp->field[j], sizeof(T));
      }
      tmp = tmp->next;
    }
  }
}

template<>
void List<string>::load_to_bin(fstream &out) {
  if (out.is_open()) {
    Node<string> *tmp = head;
    for (int i = 0; i < size; ++i) {
      out.write((char *) &(tmp->c_size), sizeof(unsigned int));
      for (int j = 0; j < tmp->c_size; ++j) {
        unsigned int sz = tmp->field[j]->length();
        out.write((char *) &sz, sizeof(unsigned int));
        out.write((char *) tmp->field[j]->c_str(), sizeof(char) * sz);
      }
      tmp = tmp->next;
    }
  }
}

template<typename T>
void List<T>::load_from_bin(fstream &in) {
  while (size != 0) {
    Node<T> *tmp = head->next;
    delete head;
    head = tmp;
    size--;
  }
  int sz;
  Node<T> *tmp;
  while (in.peek() != EOF) {
    in.read((char *) &sz, sizeof(unsigned int));
    tmp = new Node<T>(sz);
    for (int i = 0; i < sz; ++i) {
      tmp->field[i] = new T;
      in.read((char *) &(tmp[i]), sizeof(unsigned int));
      tmp->c_size++;
    }
    tmp->next = new Node<T>(tmp->length * FACTOR);
    tmp = tmp->next;
    size++;
  }
}

template<>
void List<string>::load_from_bin(fstream &in) {
  while (size != 0) {
    Node<string> *tmp = head->next;
    delete head;
    head = tmp;
    size--;
  }
  unsigned int sz;
  unsigned int el_sz;
  Node<string> *tmp;
  if (in.peek() != EOF) {
    in.read((char *) &sz, sizeof(unsigned int));
    tmp = new Node<string>(sz);
  }
  while (in.peek() != EOF) {
    for (int i = 0; i < sz; ++i) {
      in.read((char *) &el_sz, sizeof(unsigned int));
      char *el_tmp = new char[el_sz];
      in.read(el_tmp, el_sz);
      string *str = new string(el_tmp);
      tmp->field[i] = str;
      tmp->c_size++;
    }
    sz = 0;

    in.read((char *) &sz, sizeof(unsigned int));
    if (sz > 0) {
      tmp->next = new Node<string>(sz);
      tmp = tmp->next;
      size++;
    } else {
      size++;
    }
  }

}

template<typename T>
T *List<T>::get_elem(unsigned int list_num, unsigned int arr_pos) {
  if (is_empty()) {
    // TODO
    cout << "AAAAAAAAAAAAAAA!!!\n";
  }
  Node<T> *tmp = head;
  for (int i = 0; i < list_num; ++i) {
    tmp = tmp->next;
  }
  return tmp->field[arr_pos];
}

template<typename T>
void List<T>::sort() {
  Node<T> *tmp = head;
  while (tmp) {
    for (int i = 0; i < tmp->c_size - i - 1; ++i) {
      for (int j = 0; j < tmp->c_size - 1; ++j) {
        if (*(tmp->field[j]) > *(tmp->field[j + 1]))
          swap(*(tmp->field[j]), *(tmp->field[j + 1]));
      }
    }
    tmp = tmp->next;
  }
}

template
class List<int>;

template
class List<float>;

template
class List<double>;

template
class List<char>;

template
class List<unsigned int>;

template
class List<long>;

template
class List<long long>;

template
class List<short>;

template
class List<string>;
