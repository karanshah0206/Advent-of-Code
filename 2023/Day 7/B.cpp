#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<pair<vector<size_t>, size_t>> fiveOfAKind, fourOfAKind, fullHouse, threeOfAKind, twoPair, onePair, highCard;
    string s;
    cin >> s;
    while (s != "exit") {
        size_t bid;
        cin >> bid;
        vector<size_t> hand;
        map<char, size_t> handMap;
        size_t jCounter = 0;
        for (const char& c : s) {
            if (c >= '2' && c <= '9') hand.push_back(c - '0');
            else if (c == 'T') hand.push_back(10);
            else if (c == 'J') {
                hand.push_back(1);
                jCounter++;
            }
            else if (c == 'Q') hand.push_back(12);
            else if (c == 'K') hand.push_back(13);
            else hand.push_back(14);
            handMap[c] += 1;
        }
        if (handMap.size() == 1) fiveOfAKind.push_back({ hand, bid });
        else if (handMap.size() == 5) {
            if (jCounter == 0) highCard.push_back({ hand, bid });
            else onePair.push_back({ hand, bid });
        }
        else if (handMap.size() == 4) {
            if (jCounter == 0) onePair.push_back({ hand, bid });
            else threeOfAKind.push_back({ hand, bid });
        }
        else if (jCounter && handMap.size() == 2) fiveOfAKind.push_back({ hand, bid });
        else if (jCounter && handMap.size() == 3) {
            if (jCounter > 1) fourOfAKind.push_back({ hand, bid });
            else {
                size_t maxCount = 0;
                for (const char& c : s)
                    if (handMap[c] > maxCount)
                        maxCount = handMap[c];
                if (maxCount == 2) fullHouse.push_back({ hand, bid });
                else fourOfAKind.push_back({ hand, bid });
            }
        }
        else {
            size_t maxCount = 0;
            for (const char& c : s)
                if (handMap[c] > maxCount)
                    maxCount = handMap[c];
            if (handMap.size() == 3) {
                if (maxCount == 2) twoPair.push_back({ hand, bid });
                else threeOfAKind.push_back({ hand, bid });
            } else {
                if (maxCount == 3) fullHouse.push_back({ hand, bid });
                else fourOfAKind.push_back({ hand, bid });
            }
        }
        cin >> s;
    }
    sort(fiveOfAKind.begin(), fiveOfAKind.end());
    sort(fourOfAKind.begin(), fourOfAKind.end());
    sort(fullHouse.begin(), fullHouse.end());
    sort(threeOfAKind.begin(), threeOfAKind.end());
    sort(twoPair.begin(), twoPair.end());
    sort(onePair.begin(), onePair.end());
    sort(highCard.begin(), highCard.end());
    size_t result = 0, rank = 0;
    for (const auto& hand : highCard) result += ++rank * hand.second;
    for (const auto& hand : onePair) result += ++rank * hand.second;
    for (const auto& hand : twoPair) result += ++rank * hand.second;
    for (const auto& hand : threeOfAKind) result += ++rank * hand.second;
    for (const auto& hand : fullHouse) result += ++rank * hand.second;
    for (const auto& hand : fourOfAKind) result += ++rank * hand.second;
    for (const auto& hand : fiveOfAKind) result += ++rank * hand.second;
    cout << result << endl;
    return 0;
}
