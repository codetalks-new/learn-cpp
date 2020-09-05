#include <iostream>
using std::cout;
using std::endl;

template <typename T>
struct Node {
  T value;
  Node *next;
  Node() : value(nullptr), next(nullptr) {}
};

using IntPtrNode = Node<const int *>;

int main(int argc, char const *argv[]) {
  IntPtrNode *p = new IntPtrNode();
  p->value = new int(5);
  cout << p->value << endl;
  IntPtrNode *node = p;
  while (node != nullptr) {
    IntPtrNode *tmp = node;
    node = node->next;
    if (tmp->value != nullptr) {
      delete tmp->value;
      tmp->value = nullptr;
    }
    cout << p->value << endl;
    delete tmp;
  }
  cout << p->value << endl;
  return 0;
}
