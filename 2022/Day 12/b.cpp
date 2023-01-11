#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef pair<size_t, size_t> coord;

vector<vector<size_t>> grid;
coord endCoord;

bool isValidChild(queue<coord> frontier, const set<coord>& visited, const coord& current) {
  if (visited.find(current) != visited.end()) return false;
  while (!frontier.empty()) {
    if (frontier.front() == current) return false;
    frontier.pop();
  }
  return true;
}

vector<coord> getChildren(const coord& c) {
  vector<coord> res;
  int cVal = grid[c.second][c.first];
  if (c.first < grid[c.second].size() - 1 && grid[c.second][c.first + 1] >= cVal - 1)
    res.push_back({ c.first + 1, c.second });
  if (c.second < grid.size() - 1 && grid[c.second + 1][c.first] >= cVal - 1)
    res.push_back({ c.first, c.second + 1 });
  if (c.second > 0 && grid[c.second - 1][c.first] >= cVal - 1)
    res.push_back({ c.first, c.second - 1 });
  if (c.first > 0 && grid[c.second][c.first - 1] >= cVal - 1)
    res.push_back({ c.first - 1, c.second });
  return res;
}

size_t bfs() {
  map<coord, coord> childToParent;
  childToParent.insert({endCoord, endCoord});

  queue<coord> frontier;
  set<coord> visited;
  frontier.push(endCoord);

  while (!frontier.empty()) {
    coord current = frontier.front();
    frontier.pop();
    visited.insert(current);

    if (grid[current.second][current.first] == 1) {
      size_t steps = 0;
      coord q = current;
      while (q != endCoord) { q = childToParent[q]; steps++; }
      return steps;
    }

    for (const coord& c : getChildren(current)) {
      if (isValidChild(frontier, visited, c)) {
        frontier.push(c);
        childToParent.insert({c, current});
      }
    }
  }

  return -1;
}

int main() {
  string s; cin >> s;
  while (s != "exit") {
    vector<size_t> row;
    for (size_t i = 0; i < s.length(); i++) {
      char c = s[i];
      if (c == 'S') row.push_back('a' - 96);
      else if (c == 'E') {
        endCoord.first = i; endCoord.second = grid.size();
        row.push_back('z' - 96);
      }
      else row.push_back(c - 96);
    }
    grid.push_back(row);
    cin >> s;
  }
  cout << bfs() << endl;
  return 0;
}
