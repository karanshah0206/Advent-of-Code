#include <bits/stdc++.h>

using namespace std;

vector<string> grid;

bool found_reflection(int si, int ei) {
    if (si < 0 || ei >= grid.size()) return true;
    if (grid[si] != grid[ei]) return false;
    return found_reflection(si - 1, ei + 1);
}

void rotate_grid() {
    vector<string> new_grid(grid[0].size());
    for (size_t i = 0; i < grid[0].size(); i++)
        for (size_t j = 0; j < grid.size(); j++)
            new_grid[i] += grid[j][i];
    grid = new_grid;
}

int solve() {
    for (int i = 0; i < grid.size() - 1; i++)
        if (found_reflection(i, i + 1))
            return (i + 1) * 100;
    rotate_grid();
    for (int i = 0; i < grid.size() - 1; i++)
        if (found_reflection(i, i + 1))
            return i + 1;
    return 0;
}

int main() {
    size_t res = 0;
    string s;
    getline(cin, s);
    while (s != "exit") {
        if (s == "") {
            res += solve();
            grid.clear();
        }
        else grid.push_back(s);
        getline(cin, s);
    }
    cout << res << endl;
    return 0;
}
