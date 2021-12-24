#include "../include/menu.h"

void show_menu() {
  std::cout << "\n-------------------------------\n"
               " [1] -Add array-\n"
               " [2] -Insert array-\n"
               " [3] -Remove array-\n"
               " [4] -Add element-\n"
               " [5] -Remove element-\n"
               " [6] -Sort-\n"
               " [7] -Balance-\n"
               " [8] -Load from file-\n"
               " [9] -Load to file-\n"
               "[10] -Show list-\n"
               "[11] -Exit-\n"
               "-------------------------------\n";

}

void menu(List<std::string> &a) {
  unsigned int choice;
  int num;
  bool flag = true;
  std::fstream f;
  std::cin >> choice;
  while (flag) {
    show_menu();
    switch (choice) {
      case 0:flag = false;
        break;
      case 1:a.add_array();
        break;
      case 2:break;
      case 3:std::cout << "Enter position:\n";
        std::cin >> num;
        a.remove(num);
    }
  }
}