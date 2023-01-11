#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<size_t> getInput() {
  string s;
  vector<size_t> r;
  getline(cin, s, ' '); getline(cin, s, ' ');
  r.push_back(stoi(s));
  getline(cin, s, ' '); getline(cin, s, ' ');
  r.push_back(stoi(s));
  getline(cin, s, ' '); getline(cin, s);
  r.push_back(stoi(s));
  return r;
}

int main() {
  vector<stack<char>> q;
  stack<string> s;
  string f;
  getline(cin, f);
  size_t n = (f.length() + 1) / 4;
  do {
    s.push(f);
    getline(cin, f);
  } while (f[1] != '1');
  for (size_t i = 0; i < n; i++) q.push_back({});
  while (s.size() > 0) {
    string w = s.top(); s.pop();
    for (size_t i = 0; i < n; i++) if (w[4*i+1] != ' ') q[i].push(w[4*i+1]);
  }
  while (1) {
    vector<size_t> r = getInput();
    stack<char> t;
    for (size_t i = 0; i < r[0]; i++) {
      char c = q[r[1]-1].top();
      q[r[1]-1].pop();
      t.push(c);
    }
    while (t.size() > 0) { q[r[2]-1].push(t.top()); t.pop(); }
    cout << "Result: ";
    for (size_t i = 0; i < n; i++) cout << ((q[i].size() > 0) ? q[i].top() : ' ');
    cout << endl;
  }
  return 0;
}
