#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int binary_convert(string);

char most_common_in_pos(int, list<string>*, int);

int main(int argc, char const* argv[]) {
  fstream input(argv[1]);
  if (!input.is_open())
    return -1;

  string first;
  input >> first;

  list<string> co_list;
  list<string> ox_list;

  ox_list.push_back(first);
  co_list.push_back(first);

  int size = first.size();

  int cont = 0;

  while (input) {
    string binary;
    input >> binary;
    ox_list.push_back(binary);
    co_list.push_back(binary);
    cont++;
  }

  char ox[size], co[size];

  for (int i = 0; i < size; i++) {
    if (ox_list.size() != 1)
      most_common_in_pos(i, &ox_list, 1);
    else {
      break;
    }
  }

  cout << ox_list.front() << endl;

  for (int i = 0; i < size; i++) {
    if (co_list.size() != 1)
      most_common_in_pos(i, &co_list, 0);
    else {
      break;
    }
  }

  cout << co_list.front() << endl;

  cout << binary_convert(ox_list.front()) * binary_convert(co_list.front())
       << endl;

  return 0;
}

char most_common_in_pos(int pos, list<string>* b_list, int m_l) {
  list<string> o_list, z_list;

  int most = 0;

  // cout << m_l << endl;

  for (string b : *b_list) {
    // cout << b << endl;
    if (b[pos] == '1') {
      o_list.push_back(b);
      most++;
      continue;
    }
    most--;
    z_list.push_back(b);
  }

  // cout << most << endl;

  // cout << endl;

  if (m_l == 1) {
    if (most >= 0) {
      *b_list = o_list;
      return '1';
    }

    *b_list = z_list;
    return '0';
  }

  if (most < 0) {
    *b_list = o_list;
    return '1';
  }

  *b_list = z_list;
  return '0';
}

int binary_convert(string str) {
  int decimal = 0;
  int base = 1;

  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] == '1')
      decimal += base;

    base *= 2;
  }

  return decimal;
}