#include "gtest/gtest.h"
#include "../include/List.h"

TEST(lol, lol) {
  List<int> p;
  int _num = 5;
  int *num = &_num;

  for (int i = 0; i < 10000; ++i) {
    _num++;
    p.add(&_num);
  }
  std::cout << p;



}
