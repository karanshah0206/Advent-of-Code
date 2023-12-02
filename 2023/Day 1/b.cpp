#include <bits/stdc++.h>

using namespace std;

vector<int> prefixTable(string w) {
    int m = w.size();
    vector<int> r(m);
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && w[k] != w[i]) k = r[k - 1];
        if (w[k] == w[i]) k++;
        r[i] = k;
    }
    return r;
}

vector<int> searchKMP(string s, string w) {
    vector<int> result;
    int n = s.size(), m = w.size(), q = 0;
    vector<int> T = prefixTable(w);
    for (int i = 0; i < n; i++) {
        while (q > 0 && w[q] != s[i]) q = T[q - 1];
        if (w[q] == s[i]) q++;
        if (q == m) {
            result.push_back(i - m + 1);
            q = T[q - 1];
        }
    }
    return result;
}

int main() {
    size_t res = 0;
    vector<pair<string, size_t>> nums = { { "zero", 0 }, { "one", 1 }, { "two", 2 }, { "three", 3 },
        { "four", 4 }, { "five", 5} , { "six", 6} , { "seven", 7} , { "eight", 8} , { "nine", 9 } };
    string s;
    cin >> s;
    while (s != "exit") {
        vector<pair<size_t, size_t>> numPositions;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                numPositions.push_back({ i, s[i] - '0' });
            }
        }
        for (pair<string, size_t> num : nums) {
            vector<int> positions = searchKMP(s, num.first);
            for (int pos : positions) numPositions.push_back({ pos, num.second });
        }
        sort(numPositions.begin(), numPositions.end());
        res += (*numPositions.begin()).second * 10 + (*(--numPositions.end())).second;
        cin >> s;
    }
    cout << res << endl;
    return 0;
}
