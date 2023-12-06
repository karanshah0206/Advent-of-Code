#include <bits/stdc++.h>

using namespace std;

struct RangeVector {
    vector<pair<size_t, size_t>> ranges, tempRanges;

    void insert(size_t startRange, size_t endRange) {
        ranges.push_back({ startRange, endRange });
        sort(ranges.begin(), ranges.end());
    }

    void update(size_t currentStart, size_t currentEnd, size_t newStart, size_t newEnd) {
        vector<pair<size_t, size_t>> newRanges;
        for (size_t i = 0; i < ranges.size(); i++) {
            size_t rangeStart = ranges[i].first;
            size_t rangeEnd = ranges[i].second;
            if (rangeStart <= currentEnd && rangeEnd >= currentStart) {
                if (rangeStart >= currentStart) {
                    if (rangeEnd <= currentEnd) {
                        size_t diffStart = newStart + (rangeStart - currentStart);
                        size_t diffEnd = newStart + (rangeEnd - currentStart);
                        tempRanges.push_back({ diffStart, diffEnd });
                    }
                    else {
                        size_t diffStart = newStart + (rangeStart - currentStart);
                        tempRanges.push_back({ diffStart, newEnd });
                        newRanges.push_back({ currentEnd + 1, rangeEnd });
                    }
                } else {
                    newRanges.push_back({ rangeStart, currentStart - 1 });
                    if (rangeEnd > currentEnd) {
                        tempRanges.push_back({ newStart, newEnd });
                        newRanges.push_back({ currentEnd + 1, rangeEnd });
                    } else {
                        size_t diffEnd = newStart + (rangeEnd - currentStart);
                        tempRanges.push_back({ newStart, diffEnd });
                    }
                }
            } else newRanges.push_back({ rangeStart, rangeEnd });
        }
        sort(newRanges.begin(), newRanges.end());
        ranges = newRanges;
    }

    void commit() {
        for (const auto& tempRange : tempRanges) ranges.push_back({ tempRange.first, tempRange.second });
        sort(ranges.begin(), ranges.end());
        tempRanges.clear();
    }

    void showResult() {
        cout << ranges[0].first << endl;
    }
};

RangeVector getSeeds() {
    RangeVector r;
    string s; cin >> s;
    getline(cin, s);
    stringstream ss(s);
    size_t startValue, range;
    while (ss >> startValue >> range) r.insert(startValue, startValue + (range - 1));
    getline(cin, s);
    return r;
}

void getMap(RangeVector& r) {
    string s;
    getline(cin, s); getline(cin, s);
    while (s != "") {
        stringstream ss(s);
        size_t startNew, startOld, range;
        ss >> startNew >> startOld >> range;
        r.update(startOld, startOld + (range - 1), startNew, startNew + (range - 1));
        getline(cin, s);
    }
}

int main() {
    RangeVector r = getSeeds();
    for (size_t i = 0; i < 7; i++) {
        getMap(r);
        r.commit();
    }
    r.showResult();
    return 0;
}
