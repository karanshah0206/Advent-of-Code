#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
  string a, b, c;
  size_t res = 0;
  while (1) {
    cin >> a >> b >> c;
    unordered_map<char, size_t> m;
    unordered_set<char> t;
    for (const char& q : a) if (t.find(q) == t.end()) { m[q]++; t.insert(q); }
    t.clear();
    for (const char& q : b) if (t.find(q) == t.end()) { m[q]++; t.insert(q); }
    t.clear();
    for (const char& q : c) if (t.find(q) == t.end()) { m[q]++; t.insert(q); }
    for (const auto& q : m) if (q.second == 3) {
      if (q.first >= 'a' && q.first <= 'z') res += q.first - 96;
      else res += q.first - 38;
      break;
    }
    cout << endl << "Result: " << res << endl;
  }
  return 0;
}
