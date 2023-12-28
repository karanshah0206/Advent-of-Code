#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

size_t getHash(string s) {
    size_t res = 0;
    for (const char& c : s) {
        res += (int)c;
        res *= 17;
        res %= 256;
    }
    return res;
}

int main() {
    size_t res = 0;
    string s;
    ifstream f;
    vector<pair<unordered_map<string, size_t>, vector<string>>> boxes(256);
    f.open("./input.txt");
    while (getline(f, s, ',')) {
        if (s[s.size() - 1] == '-') {
            s.pop_back();
            size_t hash = getHash(s);
            boxes[hash].first.erase(s);
            boxes[hash].second.erase(remove(boxes[hash].second.begin(), boxes[hash].second.end(), s), boxes[hash].second.end());
        } else {
            string p1, p2;
            stringstream ss(s);
            getline(ss, p1, '=');
            getline(ss, p2);
            size_t hash = getHash(p1);
            size_t num = stoi(p2);
            if (!boxes[hash].first.count(p1))
                boxes[hash].second.push_back(p1);
            boxes[hash].first[p1] = num;
        }
    }
    for (size_t i = 0; i < boxes.size(); i++) {
        for (size_t j = 0; j < boxes[i].second.size(); j++) {
            res += (i + 1) * (j + 1) * boxes[i].first[boxes[i].second[j]];
        }
    }
    cout << res << endl;
    return 0;
}
