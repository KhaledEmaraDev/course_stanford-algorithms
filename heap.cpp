#include <bits/stdc++.h>

using namespace std;

template <typename T> class MinHeap {
public:
  MinHeap(initializer_list<T> list);
  void insert(T key);
  T top();
  T pop();
  void decrease(size_t index, T newValue);
  void erase(size_t index);

private:
  vector<T> arr;

  void bubbleUp(size_t index);
  void bubbleDown(size_t index);
};

template <typename T> void MinHeap<T>::bubbleUp(size_t index) {
  if (index == 0)
    return;

  size_t parent = (index - 1) / 2;
  if (arr[parent] > arr[index]) {
    swap(arr[parent], arr[index]);
    bubbleUp(parent);
  }
}

template <typename T> void MinHeap<T>::bubbleDown(size_t index) {
  size_t min_index = index;
  size_t left_child = 2 * index + 1;
  size_t right_child = 2 * index + 2;

  if (left_child < arr.size() && arr[left_child] < arr[index])
    min_index = left_child;
  if (right_child < arr.size() && arr[right_child] < arr[index])
    min_index = right_child;

  if (min_index == index)
    return;
  swap(arr[min_index], arr[index]);
  bubbleUp(min_index);
}

template <typename T>
MinHeap<T>::MinHeap(initializer_list<T> list) : arr(list) {
  for (int64_t i = arr.size() / 2 - 1; i >= 0; i--) {
    bubbleUp(i);
  }
}

template <typename T> void MinHeap<T>::insert(T key) {
  arr.push_back(key);
  bubbleUp(arr.size() - 1);
}

template <typename T> T MinHeap<T>::top() { return arr[0]; }

template <typename T> T MinHeap<T>::pop() {
  if (arr.size() < 1)
    return ~0;

  T res = arr[0];
  swap(arr[0], arr[arr.size() - 1]);
  arr.erase(--arr.end());
  bubbleDown(0);

  return res;
}

template <typename T> void MinHeap<T>::decrease(size_t index, T newValue) {
  arr[index] = newValue;
  bubbleUp(index);
}

template <typename T> void MinHeap<T>::erase(size_t index) {
  decrease(index, numeric_limits<T>::lowest());
  pop();
}

int main() {
  MinHeap<int64_t> priorityQueue{40, 30, 10, 100, 50, 15};
  priorityQueue.insert(40);
  priorityQueue.erase(0);
  priorityQueue.decrease(0, 5);
  cout << priorityQueue.pop() << " " << priorityQueue.top() << endl;
  return EXIT_SUCCESS;
}