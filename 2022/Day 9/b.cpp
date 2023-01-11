#include <iostream>
#include <set>

using namespace std;

set<pair<int, int>> visited = {{0,0}};
pair<int, int> positions[] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};

void matchTail(size_t tailIndex = 1) {  
  bool hasChanged = 0;
  int xDiff = positions[tailIndex-1].first - positions[tailIndex].first;
  int yDiff = positions[tailIndex-1].second - positions[tailIndex].second;
  if (abs(xDiff) >= 2) {
    hasChanged = 1;
    if (positions[tailIndex-1].first > positions[tailIndex].first) positions[tailIndex].first++;
    else positions[tailIndex].first--;
    if (yDiff != 0) {
      if (positions[tailIndex-1].second > positions[tailIndex].second) positions[tailIndex].second++;
      else positions[tailIndex].second--;
    }
  }
  else if (abs(yDiff) >= 2) {
    hasChanged = 1;
    if (positions[tailIndex-1].second > positions[tailIndex].second) positions[tailIndex].second++;
    else positions[tailIndex].second--;
    if (xDiff != 0) {
      if (positions[tailIndex-1].first > positions[tailIndex].first) positions[tailIndex].first++;
      else positions[tailIndex].first--;
    }
  }
  if (hasChanged && tailIndex != 9) matchTail(tailIndex+1);
  else if (tailIndex == 9) visited.insert(positions[9]);
}

int main() {
  while (1) {
    char dir; size_t c;
    cin >> dir >> c;
    while (c-- > 0) {
      if (dir == 'U') positions[0].second++;
      else if (dir == 'D') positions[0].second--;
      else if (dir == 'R') positions[0].first++;
      else positions[0].first--;
      matchTail();
    }
    cout << "Result: " << visited.size() << endl;
  }
  return 0;
}
