#include <bits/stdc++.h>

using namespace std;

int main() {
    int res = 0;
    string s;
    cin >> s;
    while (s != "exit") {
        int num1 = 0, num2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num1 = s[i] - '0';
                break;
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] >= '0' && s[i] <= '9') {
                num2 = s[i] - '0';
                break;
            }
        }
        res += ((num1 * 10) + num2);
        cin >> s;
    }
    cout << res << endl;
    return 0;
}
