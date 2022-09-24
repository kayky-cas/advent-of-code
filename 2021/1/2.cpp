#include <iostream>
#include <list>

using namespace std;

class Sum {
 public:
  int count;
  int acc;
  Sum() {
    count = 0;
    acc = 0;
  }
};

int main(int argc, char const *argv[]) {
  list<int> sums_list;

  Sum *sums[3] = {new Sum(), new Sum(), new Sum()};

  int current, count = 0;
  while (true) {
    cin >> current;
    if (current == -1) break;

    int max;

    if (count++ < 2)
      max = count;
    else
      max = 3;

    for (int i = 0; i < max; i++) {
      Sum *sum = sums[i];

      sum->count++;
      sum->acc += current;

      if (sum->count == 3) {
        sums_list.push_back(sum->acc);
        sum->acc = 0;
        sum->count = 0;
      }
    }
  }
  int previous = 0;
  count = 0;
  for (int sum : sums_list) {
    if (sum > previous) count++;
    previous = sum;
  }

  cout << count - 1 << endl;

  return 0;
}
