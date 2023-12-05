#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
vector<pair<int, int>> coordinates;

int getNumber(int row, int col, vector<vector<int>>& grid) {
    int number = 0;
    if (grid[row][col] != -1) {
        int start = col;
        while (start > 0 && grid[row][start - 1] != -1) --start;
        while (start < grid[row].size() && grid[row][start] != -1) {
            number *= 10;
            number += grid[row][start];
            grid[row][start] = -1;
            start++;
        }
    }
    return number;
}

vector<pair<int, int>> getNeighbours(pair<int, int> coordinate) {
    vector<pair<int, int>> result;
    int row = coordinate.first, col = coordinate.second;
    if (row > 0) result.push_back({ row - 1, col });
    if (col > 0) result.push_back({ row, col - 1 });
    if (row < grid.size() - 1) result.push_back({ row + 1, col });
    if (col < grid[row].size() - 1) result.push_back({ row, col + 1 });
    if (row > 0 && col > 0) result.push_back({ row - 1, col - 1 });
    if (row < grid.size() - 1 && col < grid[row].size() - 1) result.push_back({ row + 1, col + 1 });
    if (row > 0 && col < grid[row].size() - 1) result.push_back({ row - 1, col + 1 });
    if (row < grid.size() - 1 && col > 0) result.push_back({ row + 1, col - 1 });
    return result;
}

int main() {
    int result = 0;
    string s;
    cin >> s;
    while (s != "exit") {
        vector<int> row(s.size(), -1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') row[i] = s[i] - '0';
            else if (s[i] == '*') coordinates.push_back({ grid.size(), i });
        }
        grid.push_back(row);
        cin >> s;
    }
    for (pair<int, int> coordinate : coordinates) {
        vector<int> numbers;
        vector<vector<int>> Grid = grid;
        for (pair<int, int> neighbour : getNeighbours(coordinate)) {
            int row = neighbour.first, col = neighbour.second;
            int num = getNumber(row, col, Grid);
            if (num > 0) numbers.push_back(num);
        }
        if (numbers.size() == 2) result += numbers[0] * numbers[1];
    }
    cout << result << endl;
    return 0;
}
