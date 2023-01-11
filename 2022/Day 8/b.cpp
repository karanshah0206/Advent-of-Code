#include <iostream>
#include <vector>

using namespace std;

vector<vector<size_t>> trees = {};

void getInput() {
  string s; cin >> s;
  do {
    vector<size_t>t = {};
    for (const char& c : s) t.push_back(c - 48);
    trees.push_back(t);
    cin >> s;
  } while(s != "exit");
}

size_t getScore(size_t row, size_t col) {
  size_t n = 0, e = 0, w = 0, s = 0;
  size_t currentVal = trees[row][col];
  // check north
  for (int i = row - 1; i >= 0; i--) {
    n++;
    if (trees[i][col] >= currentVal) break;
  }
  // check south
  for (int i = row + 1; i < trees.size(); i++) {
    s++;
    if (trees[i][col] >= currentVal) break;
  }
  // check west
  for (int i = col - 1; i >= 0; i--) {
    w++;
    if (trees[row][i] >= currentVal) break;
  }
  // check east
  for (int i = col + 1; i < trees[0].size(); i++) {
    e++;
    if (trees[row][i] >= currentVal) break;
  }
  return n * e * w * s;
}

int main() {
  getInput();
  size_t maxScore = 0, rowLength = trees.size(), colLength = trees[0].size();
  for (size_t i = 1; i < rowLength - 1; i++)
    for (size_t j = 1; j < colLength - 1; j++) {
      size_t temp = getScore(i, j);
      if (temp > maxScore) maxScore = temp;
    }
  cout << "Result: " << maxScore << endl;
  return 0;
}
