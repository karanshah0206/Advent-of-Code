#include <iostream>
#include <string>
#include  <sstream>

using namespace std;

int main() {
  size_t lastSum = 0, currentSum = 0;
  string s;

  while (getline(cin, s))
    if (s.length() != 0) {
      istringstream iss(s);
      size_t temp;
      iss >> temp;
      currentSum += temp;
    } else {
      if (currentSum > lastSum) lastSum = currentSum;
      currentSum = 0;
      cout << endl << "Result: " << lastSum << endl;
    }

  return 0;
}
