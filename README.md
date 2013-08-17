## One Pointer Doubly Linked List

A (very) toy implementation of a doubly linked list using just a single pointer.

The key insight is that if store the bitwise-xor the logical previous and next
pointer with one another, you can retrieve either one by bitwise-xoring again
as you iterate either forwards or backwards.
