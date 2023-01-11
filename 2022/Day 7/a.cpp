#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class FileTree {
public:
  string name; size_t size; bool isDir;
  vector<FileTree*> children; FileTree* parent;
  FileTree(string name, bool isDir, FileTree* parent = nullptr, size_t size = 0) : name(name), size(size), isDir(isDir), parent(parent) { children = {}; }
  size_t calculateSize() {
    if (isDir) {
      size = 0;
      for (auto& t : children) size += t->calculateSize();
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

size_t res = 0;

void traverse(FileTree* node) {
  if (node->isDir && node->size <= 100000) res += node->size;
  for (auto& t : node->children) traverse(t);
}

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
  root->calculateSize();
  traverse(root);
  cout << "Result: " << res << endl;
  return 0;
}
