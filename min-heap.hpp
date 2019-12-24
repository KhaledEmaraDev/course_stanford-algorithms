#include <vector>

#pragma once

template <typename T> class MinHeap {
public:
  MinHeap();
  MinHeap(std::initializer_list<T> list);
  void insert(T key);
  T top();
  T pop();
  void decrease(size_t index, T newValue);
  void erase(size_t index);
  bool empty();

private:
  std::vector<T> arr;

  void bubbleUp(size_t index);
  void bubbleDown(size_t index);
};