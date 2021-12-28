#include "../include/menu.h"

void show_menu() {
  std::cout << "\n-------------------------------\n"
               " [1] -Add array-\n"
               " [2] -Insert array-\n"
               " [3] -Remove array-\n"
               " [4] -Add element-\n"
               " [5] -Insert element\n"
               " [6] -Remove element- a l p h a\n"
               " [7] -Sort- b e t a\n"
               " [8] -Balance- b e t a\n"
               " [9] -Load from file-\n"
               "[10] -Load to file-\n"
               "[11] -Show list-\n"
               "[12] -Exit-\n"
               "-------------------------------\n";
}

void menu(List<string> &a) {
  unsigned int choice;
  string *str;
  unsigned int num;
  bool flag = true;
  fstream f;

  int *nums;
  while (flag) {
    show_menu();
    cin >> choice;
    switch (choice) {
      case 12:system("cls");
        flag = false;
        break;
      case 1:system("cls");
        a.add_array();
        break;
      case 2:system("cls");
        cin >> num;
        a.insert_array(num);
        system("cls");
        break;
      case 3:system("cls");
        cout << "Enter position:\n";
        cin >> num;
        a.remove(num);
        system("cls");
        break;
      case 4:system("cls");
        cout << "Enter element:\n";
        str = new string;
        cin >> *str;
        a.add(str);
        system("cls");
        break;
      case 5:system("cls");
        cout << "Enter position:\n";
        cin >> num;
        cout << "Enter data:\n";
        str = new string;
        cin >> *str;
        a.insert_in_array(str, num);
        system("cls");
        break;
      case 6:system("cls");
        std::cout << "Enter position:\n";
        cin >> num;
        a.remove_from_array(num);
        system("cls");
        break;
      case 7:system("cls");
        a.sort();
        break;
      case 8:system("cls");
        //  a.balance();
        break;
      case 9:system("cls");
        f.open("../src/materials/data.bin", ios::binary | ios::in);
        a.load_from_bin(f);
        f.close();
        break;
      case 10:system("cls");
        f.open("../src/materials/data.bin", ios::binary | ios::out);
        a.load_to_bin(f);
        f.close();
        break;
      case 11:system("cls");
        cout << a;
        break;
      default:break;
    }
  }
}