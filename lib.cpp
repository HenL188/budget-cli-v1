#include "lib.h"
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

Budget budget(Budget i) {
  cout << "Enter amount for food: ";
  cin >> i.food;
  cout << "Enter amount for bills: ";
  cin >> i.bills;
  cout << "Enter amount for savings: ";
  cin >> i.savings;
  cout << "Enter amount for retirement: ";
  cin >> i.retirement;
  cout << "Enter amount for fun: ";
  cin >> i.fun;
  cout << "Enter amount for other: ";
  cin >> i.other;
  return i;
}

void create(Budget s) {
  std::ofstream file;
  cout << "Enter name of budget: ";
  string answer;
  cin >> answer;
  string name = answer + ".csv";
  bool exist = std::filesystem::exists(name);
  if (exist == true) {
    cout << "A budget by that name already exists\n";
    std::exit(0);
  }
  file.open(name, std::ios::out);

  for (int i = 0; i < 1; i++) {
    int total = s.bills + s.food + s.fun + s.other + s.retirement + s.savings;
    file << "Food"
         << ", "
         << "Bills"
         << ", "
         << "Savings"
         << ", "
         << "Retirement"
         << ", "
         << "Fun"
         << ", "
         << "Other"
         << ", "
         << "Total\n"
         << s.food << ", "

         << s.bills << ", " << s.savings << ", " << s.retirement << ", "

         << s.fun << ", " << s.other << ", " << total;
  }
  file.close();
}
