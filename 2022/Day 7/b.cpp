#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

map<size_t, string> fileSizes;

class FileTree {
public:
  string name; size_t size; bool isDir;
  vector<FileTree*> children; FileTree* parent;
  FileTree(string name, bool isDir, FileTree* parent = nullptr, size_t size = 0) : name(name), size(size), isDir(isDir), parent(parent) { children = {}; }
  size_t calculateSize() {
    if (isDir) {
      size = 0;
      for (auto& t : children) size += t->calculateSize();
      fileSizes.insert({size, name});
    }
    return size;
  }
  FileTree* getChildDir(string name) {
    for (auto& t : children) if (t->isDir && t->name == name) return t;
    return nullptr;
  }
  FileTree* getChildFile(string name) {
    for (auto& t : children) if (!t->isDir && t->name == name) return t;
    return nullptr;
  }
};

int main() {
  string s; getline(cin, s); // ignoring first line which is always "$ cd /"
  FileTree* root = new FileTree("/", true); // creating root directory
  FileTree* current = root;
  while (1) {
    getline(cin, s);
    // list command
    if (s == "$ ls") continue;
    // exit command
    else if (s == "$ exit") break;
    // change directory command
    else if (s[0] == '$') {
      string q = s.substr(5);
      if (q == "..") { if (current->parent != nullptr) current = current->parent; }
      else if (q == "/") { current = root; }
      else current = current->getChildDir(q);
    }
    // listing
    else {
      // listing directory
      if (s[0] == 'd') {
        string q = s.substr(4);
        if (current->getChildDir(q) == nullptr) {
          FileTree* newDir = new FileTree(q, true, current);
          current->children.push_back(newDir);
        }
      }
      // listing file
      else {
        stringstream ss(s);
        string q, r; size_t sz;
        getline(ss, q, ' '); getline(ss, r);
        sz = stoi(q);
        if (current->getChildFile(r) == nullptr) {
          FileTree* newFile = new FileTree(r, false, current, sz);
          current->children.push_back(newFile);
        }
      }
    }
  }
  size_t spaceToClear = 30000000 - (70000000 - root->calculateSize());
  for (const auto& i : fileSizes)
    if (i.first >= spaceToClear) {
      cout << "Result: " << i.first << " " << i.second << endl;
      return 0;
    }
  cout << "Result: No single such directory";
  return 0;
}
