#include <bits/stdc++.h>

using namespace std;

long long predict(vector<long long> v) {
    bool allZeroes = true;
    for (const auto& val : v)
        if (val) {
            allZeroes = false;
            break;
        }
    if (allZeroes) return 0;
    vector<long long> newV;
    for (long long i = 0; i < v.size() - 1; i++)
        newV.push_back(v[i + 1] - v[i]);
    return v[v.size() - 1] + predict(newV);
}

int main() {
    long long res = 0;
    string s;
    getline(cin, s);
    while (s != "exit") {
        vector<long long> v;
        long long x;
        stringstream ss(s);
        while (ss >> x) v.push_back(x);
        res += predict(v);
        getline(cin, s);
    }
    cout << res << endl;
    return 0;
}
