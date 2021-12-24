#include "../include/menu.h"


void show_menu() {
  std::cout <<"\n-------------------------------\n"
              " [1] -Add array-\n"
              " [2] -Insert array-\n"
              " [3] -Remove array-\n"
              " [4] -Add element-\n"
              " [5] -Remove element- b e t a\n"
              " [6] -Sort- b e t a\n"
              " [7] -Balance- b e t a\n"
              " [8] -Load from file- b e t a\n"
              " [9] -Load to file-\n"
              "[10] -Show list-\n"
              "[11] -Exit-\n"
              "-------------------------------\n";

}

void menu(List<std::string> &a) {
  unsigned int choice;
  std::string str;
  unsigned int num;
  bool flag = true;
  std::fstream f;

  while (flag) {
    show_menu();
    std::cin >> choice;
    // fixme
    switch (choice) {
      case 11:system("cls");
        flag = false;
        break;
      case 1:system("cls");
        a.add_array();
        break;
      case 2:system("cls");
        std::cin >> num;
        a.insert_array(num);
        break;
      case 3:system("cls");
        std::cout << "Enter position:\n";
        std::cin >> num;
        a.remove(num);
        break;
      case 4:system("cls");
        std::cin >> str;
        a.add(&str);
        break;
      case 5:system("cls");
        std::cout << "Enter position:\n";
        std::cin >> num;
       // a.remove_from_array(num);
        break;
      case 6:system("cls");
      //  a.sort();
        break;
      case 7:system("cls");
      //  a.balance();
        break;
      case 8:system("cls");
      //  a.load_from_bin(f);
        break;
      case 9:system("cls");
        a.load_to_bin(f);
        break;
      case 10:system("cls");
        std::cout << a;
        break;
      default:break;
    }
  }
}