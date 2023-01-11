#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
  string s; size_t r = 0;
  while (getline(cin, s)) {
    unordered_map<char, size_t> t;
    unordered_set<char> w;
    string q = s.substr(0, s.length()/2);
    s.erase(0, s.length()/2);
    for (const char& c : q) if (w.find(c) == w.end()) { t[c]++; w.insert(c); }
    w.clear();
    for (const char& c : s) if (w.find(c) == w.end()) { t[c]++; w.insert(c); }
    for (const auto& c : t)
      if (c.second > 1) {
        if (c.first >= 'a' && c.first <= 'z') r += c.first - 96;
        else r += c.first - 38;
      }
    cout << endl << "Result: " << r << endl;
  }
  return 0;
}
