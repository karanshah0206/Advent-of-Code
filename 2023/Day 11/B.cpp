#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> grid;
    vector<pair<long long, long long>> galaxy_coordinates;
    string s;
    cin >> s;
    while (s != "exit") {
        grid.push_back(s);
        cin >> s;
    }
    set<long long> row_expands, col_expands;
    for (long long i = 0; i < grid.size(); i++) {
        bool found = false;
        for (long long j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '#') {
                found = true;
                break;
            }
        }
        if (!found) row_expands.insert(i);
    }
    for (long long i = 0; i < grid[0].size(); i++) {
        bool found = false;
        for (long long j = 0; j < grid.size(); j++) {
            if (grid[j][i] == '#') {
                found = true;
                break;
            }
        }
        if (!found) col_expands.insert(i);
    }
    for (long long i = 0; i < grid.size(); i++) {
        for (long long j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '#') {
                galaxy_coordinates.push_back({ i, j });
            }
        }
    }
    long long res = 0;
    for (long long i = 0; i < galaxy_coordinates.size() - 1; i++) {
        for (long long j = i + 1; j < galaxy_coordinates.size(); j++) {
            res += abs(galaxy_coordinates[i].first - galaxy_coordinates[j].first) + abs(galaxy_coordinates[i].second - galaxy_coordinates[j].second);
            long long c = 0;
            for (long long k = min(galaxy_coordinates[i].first, galaxy_coordinates[j].first); k < max(galaxy_coordinates[i].first, galaxy_coordinates[j].first); k++)
                if (row_expands.count(k))
                    c++;
            for (long long k = min(galaxy_coordinates[i].second, galaxy_coordinates[j].second); k < max(galaxy_coordinates[i].second, galaxy_coordinates[j].second); k++)
                if (col_expands.count(k))
                    c++;
            res += (1000000 - 1) * c;
        }
    }
    cout << res << endl;
    return 0;
}
