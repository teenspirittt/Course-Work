#include "../include/menu.h"

void show_menu() {

  std::cout << "\n-------------------------------\n"
               " [1] -Add array-\n"
               " [2] -Insert array-\n"
               " [3] -Remove array-\n"
               " [4] -Add element-\n"
               " [5] -Insert element\n"
               " [6] -Remove element-\n"
               " [7] -Sort-\n"
               " [8] -Balance-\n"
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
  while (flag) {
    show_menu();
    cin >> choice;
    switch (choice) {
      case 12:system("cls");
        flag = false;
        break;
      case 1:system("cls");
        a.add_arr();
        break;
      case 2:system("cls");
        cout << "Enter position:\n";
        cin >> num;
        try {
          a.insert_arr(num);
        } catch (exception &ex) {
          cout << endl << ex.what();
        }
        break;
      case 3:system("cls");
        cout << "Enter position:\n";
        cin >> num;
        try {
          a.remove_arr(num);
        } catch (exception &ex) {
          cout << endl << ex.what();
        }
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
        try {
          a.insert(str, num);
        } catch (exception &ex) {
          cout << endl << ex.what();
        }
        break;
      case 6:system("cls");
        std::cout << "Enter position:\n";
        cin >> num;
        try {
          a.remove(num);
        } catch (exception &ex) {
          cout << endl << ex.what();
        }
        break;
      case 7:system("cls");
        a.sort();
        break;
      case 8:system("cls");
        a.balance();
        break;
      case 9:system("cls");
        f.open("../src/materials/data.bin", ios::binary | ios::in);
        a.read_bin(f);
        f.close();
        break;
      case 10:system("cls");
        f.open("../src/materials/data.bin", ios::binary | ios::out);
        a.write_bin(f);
        f.close();
        break;
      case 11:system("cls");
        cout << a;
        break;
      default:system("cls");
        cout << "n/a number of menu!";
        break;
    }
  }
}