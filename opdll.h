#ifndef __OPDLL_H__
#define __OPDLL_H__

#include <assert.h>

template<typename T>
struct Node {
  Node(const T& val) : val(val), ptr(nullptr) {}

  // ptr holds to bitwise-xor of previous pointer and next pointer
  Node<T>* ptr;
  T val;
};

template<typename T>
struct DoublyLinkedList {
  Node<T>* head_;
  Node<T>* tail_;
  DoublyLinkedList() : head_(nullptr), tail_(nullptr) {}

  Node<T>* next(const Node<T>* const prev, const Node<T>& node) const {
    // xor out the previous pointer to get the next pointer
    return reinterpret_cast<Node<T>*>(reinterpret_cast<uintptr_t>(node.ptr) ^ reinterpret_cast<uintptr_t>(prev));
  }

  Node<T>* prev(const Node<T>* const next, const Node<T>& node) const {
    // xor out the next pointer to get the previous pointer
    return reinterpret_cast<Node<T>*>(reinterpret_cast<uintptr_t>(node.ptr) ^ reinterpret_cast<uintptr_t>(next));
  }

  void append(const T& val) {
    if (tail_ == nullptr) {
      assert(head_ == nullptr);
      head_ = new Node<T>(val);
      tail_ = head_;
    } else {
      assert(head_ != nullptr);
      Node<T>* tmp = new Node<T>(val);
      // xor the old tail ptr
      tail_->ptr = reinterpret_cast<Node<T>*>(reinterpret_cast<uintptr_t>(tail_->ptr) ^ reinterpret_cast<uintptr_t>(tmp));
      tmp->ptr = tail_;
      tail_ = tmp;
    }
  }

  void prepend(const T& val) {
    if (head_ == nullptr) {
      assert(tail_ == nullptr);
      head_ = new Node<T>(val);
      tail_ = head_;
    } else {
      assert(tail_ != nullptr);
      Node<T>* tmp = new Node<T>(val);
      // xor the old tail ptr
      head_->ptr = reinterpret_cast<Node<T>*>(reinterpret_cast<uintptr_t>(head_->ptr) ^ reinterpret_cast<uintptr_t>(tmp));
      tmp->ptr = head_;
      head_ = tmp;
    }
  }
};

#endif
