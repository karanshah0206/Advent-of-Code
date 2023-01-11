#include <iostream>
#include <string>

using namespace std;

int main() {
  size_t c = 0;
  while (1) {
    string n1, n2, n3, n4;
    int o, t, tr, f;
    getline(cin, n1, '-');
    getline(cin, n2, ',');
    getline(cin, n3, '-');
    getline(cin, n4);
    o = stoi(n1); t = stoi(n2); tr = stoi(n3); f = stoi(n4);
    if ((o >= tr && t <= f) || (tr >= o && f <= t)) c++;
    cout << endl << "Result: " << c << endl;
  }
  return 0;
}
