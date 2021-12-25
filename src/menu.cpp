#include "../include/menu.h"

void show_menu() {
  std::cout << "\n-------------------------------\n"
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

void menu(List<string> &a) {
  unsigned int choice;
  string str;
  unsigned int num;
  bool flag = true;
  fstream f;
  int heh;
  int *nums;
  nums = &heh;
  while (flag) {
    show_menu();
    cin >> choice;
    // fixme
    switch (choice) {
      case 11:system("cls");
        flag = false;
        break;
      case 1:system("cls");
        a.add_array();
        break;
      case 2:system("cls");
        cin >> num;
        a.insert_array(num);
        break;
      case 3:system("cls");
        cout << "Enter position:\n";
        cin >> num;
        a.remove(num);
        break;
      case 4:system("cls");
        cin >> str;
        a.add(&str);
        break;
      case 5:system("cls");
        std::cout << "Enter position:\n";
        cin >> num;
        // a.remove_from_array(num);
        break;
      case 6:system("cls");
        //  a.sort();
        break;
      case 7:system("cls");
        //  a.balance();
        break;
      case 8:system("cls");
        f.open("../src/materials/data.bin", std::ios::binary | std::ios::in);
        a.load_from_bin(f);
        f.close();
        break;
      case 9:system("cls");
        f.open("../src/materials/data.bin", std::ios::binary | std::ios::out);
        a.load_to_bin(f);
        f.close();
        break;
      case 10:system("cls");
        cout << a;
        break;
      default:break;
    }
  }
}