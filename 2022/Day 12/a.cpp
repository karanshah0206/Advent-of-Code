#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef pair<size_t, size_t> coord;

bool checkValidChildren(queue<coord> frontier, const set<coord>& visited, const coord& current) {
  if (visited.find(current) != visited.end()) return false;
  while (!frontier.empty()) {
    if (frontier.front() == current) return false;
    frontier.pop();
  }
  return true;
}

vector<coord> generateChildren(const vector<vector<size_t>>& grid, const coord& c) {
  vector<coord> res;
  size_t cVal = grid[c.second][c.first];
  if (c.first < grid[c.second].size() - 1 && grid[c.second][c.first + 1] <= cVal + 1)
    res.push_back({ c.first + 1, c.second });
  if (c.second < grid.size() - 1 && grid[c.second + 1][c.first] <= cVal + 1)
    res.push_back({ c.first, c.second + 1 });
  if (c.second > 0 && grid[c.second - 1][c.first] <= cVal + 1)
    res.push_back({ c.first, c.second - 1 });
  if (c.first > 0 && grid[c.second][c.first - 1] <= cVal + 1)
    res.push_back({ c.first - 1, c.second });
  return res;
}

int bfs(const vector<vector<size_t>>& grid, const coord& start, const coord& end) {
  map<coord, coord> childToParentMap;
  childToParentMap.insert({start, start});

  queue<coord> frontier;
  set<coord> visited;
  frontier.push(start);

  while (!frontier.empty()) {
    coord current = frontier.front();
    frontier.pop();
    visited.insert(current);

    if (current == end) {
      size_t steps = 0;
      coord q = end;
      while (q != start) { q = childToParentMap[q]; steps++; };
      return steps;
    }

    for (const coord& c : generateChildren(grid, current))
      if (checkValidChildren(frontier, visited, c)) {
        frontier.push(c);
        childToParentMap.insert({c, current});
      }
  }
  return -1;
}

int main() {
  vector<vector<size_t>> grid;
  coord start = {0,0}, end = {0,0};
  string s; cin >> s;
  while (s != "exit") {
    vector<size_t> row;
    for (size_t i = 0; i < s.length(); i++) {
      const char c = s[i];
      if (c == 'S') {
        start.first = i;
        start.second = grid.size();
        row.push_back(1);
      }
      else if (c == 'E') {
        end.first = i;
        end.second = grid.size();
        row.push_back(26);
      }
      else row.push_back(c - 96);
    }
    grid.push_back(row);
    cin >> s;
  }
  cout << bfs(grid, start, end) << endl;
  return 0;
}
