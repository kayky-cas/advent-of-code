#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int binary_convert(string);

int main(int argc, char const *argv[]) {
  fstream input(argv[1]);
  if (!input.is_open()) return -1;

  string first;
  input >> first;

  int size = first.size();

  list<string> b_list;

  while (input) {
    string binary;
    input >> binary;
    b_list.push_back(binary);
  }

  return 0;
}

int binary_convert(string str) {
  int decimal = 0;
  int base = 1;

  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] == '1') {
      decimal += base;
    }

    base *= 2;
  }

  return decimal;
}