#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    size_t res = 0;
    string s;
    ifstream f;
    f.open("./input.txt");
    while (getline(f, s, ',')) {
        size_t tres = 0;
        for (const char& c : s) {
            tres += (int)c;
            tres *= 17;
            tres %= 256;
        }
        res += tres;
    }
    cout << res << endl;
    return 0;
}
