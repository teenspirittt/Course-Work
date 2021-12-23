#include "gtest/gtest.h"
#include "../include/List.h"

TEST(lol, lol) {
  List<int> p;
  int _num = 5;
  int *num = &_num;

  (*num)++;
  p.add(num);
  (*num)++;
  p.add(num);
  (*num)++;
  p.add(num);
  (*num)++;
  p.add(num);
  p.remove();

  std::cout << *(p.get(0, 0)) << std::endl;
  std::cout << *(p.get(0, 1)) << std::endl;
  std::cout << *(p.get(1, 0)) << std::endl;
  std::cout << *(p.get(1, 1)) << std::endl;

}
