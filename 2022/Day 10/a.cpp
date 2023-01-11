#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<size_t> importantCycles = {20, 60, 100, 140, 180, 220};
int res = 0, xRegister = 1, cycle = 0;

void tick() {
  cycle++;
  if (importantCycles.find(cycle) != importantCycles.end()) res += (xRegister * cycle);
}

int main() {
  while (1) {
    string s; cin >> s;
    if (s == "noop") tick();
    else {
      int r; cin >> r;
      tick(); tick();
      xRegister += r;
    }
    cout << "Result: " << res << endl;
  }
  return 0;
}
