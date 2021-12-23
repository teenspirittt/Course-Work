#include "gtest/gtest.h"
#include "../include/List.h"

TEST(lol, lol) {
  List<int> p;
  int _num = 5;
  int *num = &_num;

  for (int i = 0; i < 100; ++i) {
    _num++;
    p.add(&_num);
  }
  std::cout << p;
  std::fstream f;
  f.open("../src/materials/data.bin", std::ios::binary | std::ios::out);
  p.load_to_bin(f);
  f.close();

}
