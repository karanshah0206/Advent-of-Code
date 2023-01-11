#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  size_t c = 4;
  string s;
  cin >> s;
  for (size_t i = 0; i <= s.size() - 4; i++) {
    unordered_set<char> q;
    q.insert(s[i]); q.insert(s[i+1]); q.insert(s[i+2]); q.insert(s[i+3]);
    if (q.size() == 4) break;
    c++;
  }
  cout << "Result: " << c << endl;
  return 0;
}
