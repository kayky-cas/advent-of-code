#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace std;

void input_queue_to_int(list<int>*, string);

int main(int argc, char const* argv[]) {
  string file_name = "test.txt";

  if (argc > 1)
    file_name = argv[1];

  fstream file_input(file_name);
  if (!file_input.is_open())
    return -1;

  string input;

  file_input >> input;

  list<int> numbers;

  input_queue_to_int(&numbers, input);

  int num;

  int tables[100][5][5];

  int l = 0, c = 0, count = 0;

  while (file_input >> num) {
    if (l == 5) {
      l = 0;
      c++;
    }

    if (c == 5) {
      c = 0;
      count++;
    }

    tables[count][c][l++] = num;
  }

  int results[count + 1][5][5];

  bool stop = false;

  int last_number;

  int loose_board;

  int winners[count + 1];
  int winners_count = 0;

  for (int i = 0; i < count + 1; i++) {
    winners[i] = 0;
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        results[i][j][k] = 0;
      }
    }
  }

  for (int actual : numbers) {
    for (int i = 0; i < count + 1; i++) {
      if (winners[i] > 0)
        continue;
      for (int j = 0; j < 5; j++) {
        int line_count = 0;
        int column_count = 0;
        for (int k = 0; k < 5; k++) {
          if (tables[i][j][k] == actual) {
            results[i][j][k]++;
          }

          if (results[i][j][k] > 0)
            line_count++;
          if (results[i][k][j] > 0)
            column_count++;
        }
        if (line_count == 5 || column_count == 5) {
          winners[i]++;
          winners_count++;
          last_number = actual;
          if (winners_count == count + 1) {
            stop = true;
            loose_board = i;
          }
          break;
        }
      }
      if (stop)
        break;
    }

    if (stop)
      break;
  }

  int sum = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (results[loose_board][i][j] == 0) {
        sum += tables[loose_board][i][j];
      }
    }
  }

  cout << last_number << endl;

  cout << sum << endl;

  cout << sum * last_number << endl;

  return 0;
}

void input_queue_to_int(list<int>* n_list, string input) {
  stringstream input_stream(input);

  string number;

  while (!input_stream.eof()) {
    getline(input_stream, number, ',');
    n_list->push_back(stoi(number));
  }
}