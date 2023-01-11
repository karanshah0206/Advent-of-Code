#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main() {
  string s;
  set<size_t> nums;
  size_t currentNum = 0;
  while (getline(cin, s))
    if (s == "~") break;
    else if (s.length() != 0) {
      istringstream iss(s);
      size_t temp;
      iss >> temp;
      currentNum += temp;
    } else {
      if (nums.size() < 3) nums.insert(currentNum);
      else if ((*nums.begin()) < currentNum) {
        nums.erase(nums.begin());
        nums.insert(currentNum);
      }
      currentNum = 0;
    }
  currentNum = 0;
  for (const size_t& i : nums) currentNum += i;
  cout << endl << "Result: " << currentNum << endl;
  return 0;
}
