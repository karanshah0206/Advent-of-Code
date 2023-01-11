#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Monkey {
public:
  size_t id;
  size_t itemsInspected;
  vector<size_t> items;

  bool operationType; // true = multiple, false = add
  size_t operationValue, testValue, testPassMonkeyId, testFailMonkeyId;

  Monkey(size_t aId, bool aOperationType, size_t aOperationValue, size_t aTestValue, size_t testPass, size_t testFail) {
    id = aId;
    operationType = aOperationType;
    operationValue = aOperationValue;
    testValue = aTestValue;
    testPassMonkeyId = testPass;
    testFailMonkeyId = testFail;
    itemsInspected = 0;
    items = {};
  }
};

vector<Monkey> monkeys = {};

void playRound(Monkey& m) {
  while (m.items.size() > 0) {
    m.itemsInspected++;
    if (m.operationValue != 0) m.items[0] = (m.operationType) ? (m.items[0] * m.operationValue) : (m.items[0] + m.operationValue);
    else m.items[0] = (m.operationType) ? (m.items[0] * m.items[0]) : (m.items[0] + m.items[0]);
    m.items[0] /= 3;
    if (m.items[0] % m.testValue == 0) monkeys[m.testPassMonkeyId].items.push_back(m.items[0]);
    else monkeys[m.testFailMonkeyId].items.push_back(m.items[0]);
    m.items.erase(m.items.begin());
  }
}

void createMonkeys() {
  string s = "";
  size_t i = 0;
  while (1) {
    vector<size_t> priorities = {}; bool opType; size_t opValue = 0, testVal, m1, m2;
    cin >> s; // eat "Monkey"
    if (s == "exit") break;
    cin >> s; // eat "{id:}"
    cin >> s; cin >> s; // eat "Starting items:"
    cin >> s;
    while (s != "Operation:") {
      if (s[s.length() - 1] == ',') s = s.substr(0, s.length() -1);
      priorities.push_back(stoi(s));
      cin >> s;
    }
    cin >> s; cin >> s; cin >> s; // eat "new = old";
    cin >> s; opType = (s == "*");
    cin >> s; if (s != "old") opValue = stoi(s);
    cin >> s; cin >> s; cin >> s; // eat "Test: divisble by"
    cin >> s; testVal = stoi(s);
    for (size_t i = 0; i < 5; i++) cin >> s; // eat "If true: throw to monkey"
    cin >> s; m1 = stoi(s);
    for (size_t i = 0; i < 5; i++) cin >> s; // eat "If false: throw to monkey"
    cin >> s; m2 = stoi(s);
    Monkey m(i, opType, opValue, testVal, m1, m2);
    for (const size_t& p : priorities) m.items.push_back(p);
    monkeys.push_back(m);
    i++;
  }
}

void play20Rounds() {
  for (size_t i = 0; i < 20; i++) for (Monkey& m : monkeys) playRound(m);
}

void getOutput() {
  // scores[0] must be greater than score[1], only 2 items must be stored in this vector
  vector<size_t> scores = {};
  for (const Monkey& m : monkeys) {
    if (scores.size() == 0) scores.push_back(m.itemsInspected);
    else if (scores.size() == 1) {
      if (scores[0] > m.itemsInspected) scores.push_back(m.itemsInspected);
      else {
        size_t temp = scores[0];
        scores[0] = m.itemsInspected;
        scores.push_back(temp);
      }
    }
    else {
      if (scores[1] >= m.itemsInspected) continue;
      if (scores[0] >= m.itemsInspected) scores[1] = m.itemsInspected;
      else {
        size_t temp = scores[0];
        scores[0] = m.itemsInspected;
        scores[1] = temp;
      }
    }
  }
  cout << "Result: " << scores[0] * scores[1] << endl;
}

int main() {
  createMonkeys();
  play20Rounds();
  getOutput();
  return 0;
}
