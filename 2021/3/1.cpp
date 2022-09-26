#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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

int main(int argc, char const *argv[]) {
  fstream input(argv[1]);
  if (input.is_open()) {
    string first;
    input >> first;

    int size = first.size();

    cout << size << endl;

    int most[size];

    for (int i = 0; i < size; i++) {
      most[i] = 0;
    }

    while (input) {
      string str;
      input >> str;

      for (int i = 0; i < size; i++) {
        if (str[i] == '1') {
          most[i]++;
          continue;
        }
        most[i]--;
      }
    }

    string gamma;
    string epsilon;

    for (int i = 0; i < size; i++) {
      if (most[i] > 0) {
        gamma.append("1");
        epsilon.append("0");
        continue;
      }

      gamma.append("0");
      epsilon.append("1");
    }

    cout << binary_convert(gamma) << endl;

    cout << (binary_convert(gamma) * binary_convert(epsilon)) << endl;
  }
  // while (true) {
  //   char str[size];
  //   cin >> str;
  //   if (str[0] == 'q') break;
  // }
}
