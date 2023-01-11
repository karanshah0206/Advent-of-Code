#include <iostream>
#include <unordered_set>

using namespace std;

bool display[6][40];
int xRegister = 1, cycle = 0;

void drawDisplay() {
  for (size_t i = 0; i <= 5; i++) {
    for (size_t j = 0; j <= 39; j++)
      if (display[i][j]) cout << "#";
      else cout << ".";
    cout << endl;
  }
}

void tick() {
  int row = cycle / 40, col = cycle % 40;
  if (abs(col - xRegister) <= 1) display[row][col] = true;
  cycle++;
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
    cout << "Result: " << endl; drawDisplay();
  }
  return 0;
}
