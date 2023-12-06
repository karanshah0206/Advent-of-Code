#include <bits/stdc++.h>

using namespace std;

vector<size_t> getSeeds() {
    vector<size_t> res;
    string s; cin >> s;
    getline(cin, s);
    stringstream ss(s);
    size_t seed;
    while (ss >> seed) res.push_back(seed);
    getline(cin, s);
    return res;
}

void getMap(vector<size_t>& v) {
    map<size_t, size_t> m;
    for (const auto& val : v) m[val] = val;
    string s; getline(cin, s);
    getline(cin, s);
    while (s != "") {
        stringstream ss(s);
        size_t dest_start, source_start, range;
        ss >> dest_start >> source_start >> range;
        for (auto& t : m)
            if (t.first >= source_start && t.first < source_start + range)
                t.second = dest_start + (t.first - source_start);
        getline(cin, s);
    }
    v.clear();
    for (const auto& t : m) v.push_back(t.second);
}

int main() {
    vector<size_t> m = getSeeds();
    for (size_t i = 0; i < 7; i++) getMap(m);
    size_t res = 1e12;
    for (const auto& v : m) if (v < res) res = v;
    cout << res << endl;
    return 0;
}
