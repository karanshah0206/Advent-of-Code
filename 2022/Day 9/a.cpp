#include <iostream>
#include <set>

using namespace std;

set<pair<int, int>> positions = {{0,0}};
pair<int, int> head = {0,0}, tail = {0,0};

void matchTail() {
  int yDiff = head.second - tail.second;
  int xDiff = head.first - tail.first;
  if (abs(xDiff) >= 2) {
    if (head.first > tail.first) tail.first++;
    else tail.first--;
    if (yDiff != 0) {
      if (head.second > tail.second) tail.second++;
      else tail.second--;
    }
  }
  if (abs(yDiff) >= 2) {
    if (head.second > tail.second) tail.second++;
    else tail.second--;
    if (xDiff != 0) {
      if (head.first > tail.first) tail.first++;
      else tail.first--;
    }
  }
  positions.insert(tail);
}

int main() {
  while (1) {
    char dir; size_t c;
    cin >> dir >> c;
    while (c-- > 0) {
      if (dir == 'U') head.second++;
      else if (dir == 'D') head.second--;
      else  if (dir == 'R') head.first++;
      else head.first--;
      matchTail();
    }
    cout << "Result: " << positions.size() << endl;
  }
  return 0;
}
