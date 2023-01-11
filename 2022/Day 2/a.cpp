#include <iostream>
#include <map>

using namespace std;

map<pair<char, char>, size_t> s = {
  {{'A', 'X'}, 4}, {{'A', 'Y'}, 8}, {{'A', 'Z'}, 3},
  {{'B', 'X'}, 1}, {{'B', 'Y'}, 5}, {{'B', 'Z'}, 9},
  {{'C', 'X'}, 7}, {{'C', 'Y'}, 2}, {{'C', 'Z'}, 6},
};

int main() {
  size_t res = 0;
  char a, b;
  while (cin >> a >> b) {
    res += s[{a, b}];
    cout << "Result: " << res << endl;
  }
  return 0;
}
