#include <iostream>
#include <vector>

using namespace std;

vector<vector<size_t>> trees = {};

bool check(size_t row, size_t col) {
  size_t currentVal = trees[row][col];
  // check north
  bool broken = false;
  for (int i = row - 1; i >= 0; i--) if (trees[i][col] >= currentVal) { broken = true; break; }
  if (!broken) return true;
  // check south
  broken = false;
  for (int i = row + 1; i < trees.size(); i++) if (trees[i][col] >= currentVal) { broken = true; break; }
  if (!broken) return true;
  // check west
  broken = false;
  for (int i = col - 1; i >= 0; i--) if (trees[row][i] >= currentVal) { broken = true; break; }
  if (!broken) return true;
  // check east
  broken = false;
  for (int i = col + 1; i < trees[0].size(); i++) if (trees[row][i] >= currentVal) { broken = true; break; }
  return !broken;
}

void getInput() {
  string s; cin >> s;
  do {
    vector<size_t>t = {};
    for (const char& c : s) t.push_back(c - 48);
    trees.push_back(t);
    cin >> s;
  } while(s != "exit");
}

int main() {
  getInput();
  size_t rowLength = trees.size(), colLength = trees[0].size(), res = 0;
  res += (rowLength * 2) + ((colLength - 2) * 2);
  for (size_t i = 1; i < rowLength - 1; i++)
    for (size_t j = 1; j < colLength - 1; j++)
      if (check(i, j)) res++;
  cout << "Result: " << res << endl;
  return 0;
}
