#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> grid;
    vector<pair<int, int>> galaxy_coordinates;
    string s;
    cin >> s;
    while (s != "exit") {
        grid.push_back(s);
        cin >> s;
    }
    vector<int> expands;
    for (int i = 0; i < grid.size(); i++) {
        bool found = false;
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '#') {
                found = true;
                break;
            }
        }
        if (!found) expands.push_back(i);
    }
    int insertedCount = 0;
    for (const int& i : expands) {
        string s = "";
        for (int j = 0; j < grid[0].size(); j++) s += ".";
        grid.insert(grid.begin() + i + insertedCount, s);
        insertedCount++;
    }
    expands.clear();
    insertedCount = 0;
    for (int i = 0; i < grid[0].size(); i++) {
        bool found = false;
        for (int j = 0; j < grid.size(); j++) {
            if (grid[j][i] == '#') {
                found = true;
                break;
            }
        }
        if (!found) expands.push_back(i);
    }
    for (const int& i : expands) {
        for (int j = 0; j < grid.size(); j++) {
            grid[j].insert(grid[j].begin() + i + insertedCount, '.');
        }
        insertedCount++;
    }
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '#') {
                galaxy_coordinates.push_back({ i, j });
            }
        }
    }
    int res = 0;
    for (int i = 0; i < galaxy_coordinates.size() - 1; i++) {
        for (int j = i + 1; j < galaxy_coordinates.size(); j++) {
            res += abs(galaxy_coordinates[i].first - galaxy_coordinates[j].first) + abs(galaxy_coordinates[i].second - galaxy_coordinates[j].second);
        }
    }
    cout << res << endl;
    return 0;
}
