#include "opdll.h"
#include <stdio.h>

int main(int argc, const char** argv) {
  DoublyLinkedList<int> dll;
  printf("Appending...\n");
  for (int i = 50; i < 100; i++) {
    dll.append(i);
  }
  for (int i = 49; i >= 0; i--) {
    dll.prepend(i);
  }
  printf("Prepending...\n");
  auto prev = static_cast<Node<int>*>(nullptr);
  auto cur = dll.head_;
  printf("Verifying forwards...");
  for (int i = 0; i < 100; i++) {
    assert(cur->val == i);
    auto tmp = cur;
    cur = dll.next(prev, *cur);
    prev = tmp;
  }
  printf(" done.\n");
  printf("Verifying backwards...");
  prev = static_cast<Node<int>*>(nullptr);
  cur = dll.tail_;
  for (int i = 99; i >= 0; i--) {
    assert(cur->val == i);
    auto tmp = cur;
    cur = dll.prev(prev, *cur);
    prev = tmp;
  }
  printf(" done.\n");
}
