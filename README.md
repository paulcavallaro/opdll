## One Pointer Doubly Linked List

A (very) toy implementation of a doubly linked list using just a single pointer.

The key insight is that if you store the bitwise-xor of the logical previous and
next pointer with one another, you can retrieve either one by bitwise-xoring
again as you iterate either forwards or backwards (since you know where you came
from). The head and tail have the nice property that the nullptr xored with
another pointer is just that pointer, so the head and tail just point to their
respective neighbors.
