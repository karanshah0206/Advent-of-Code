#include <iostream>
#include <map>

using namespace std;

map<pair<char, char>, size_t> s = {
  {{'A', 'X'}, 4}, {{'A', 'Y'}, 8}, {{'A', 'Z'}, 3},
  {{'B', 'X'}, 1}, {{'B', 'Y'}, 5}, {{'B', 'Z'}, 9},
  {{'C', 'X'}, 7}, {{'C', 'Y'}, 2}, {{'C', 'Z'}, 6},
};

map<pair<char, char>, char> t = {
  {{'A', 'X'}, 'Z'}, {{'A', 'Y'}, 'X'}, {{'A', 'Z'}, 'Y'},
  {{'B', 'X'}, 'X'}, {{'B', 'Y'}, 'Y'}, {{'B', 'Z'}, 'Z'},
  {{'C', 'X'}, 'Y'}, {{'C', 'Y'}, 'Z'}, {{'C', 'Z'}, 'X'},
};

int main() {
  char a, b;
  size_t res = 0;
  while (cin >> a >> b) {
    res += s[{a, t[{a, b}]}];
    cout << "Result: " << res << endl;
  }
  return 0;
}
