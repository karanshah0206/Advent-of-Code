#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  size_t c = 14;
  string s;
  cin >> s;
  for (size_t i = 0; i <= s.size() - 14; i++) {
    unordered_set<char> q;
    for (size_t j = 0; j < 14; j++) q.insert(s[i+j]);
    if (q.size() == 14) break;
    c++;
  }
  cout << "Result: " << c << endl;
  return 0;
}
