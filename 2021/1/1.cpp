#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int last, current, count = 0;
  cin >> current;
  while (true) {
    last = current;
    cin >> current;

    if (current == -1) break;

    if (current > last) count++;
  }

  cout << count << endl;
  return 0;
}
