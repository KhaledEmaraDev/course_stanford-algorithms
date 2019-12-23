#include <bits/stdc++.h>

using namespace std;

template <typename T> class MinHeap {
public:
  void insert(T key);
  T extract();

private:
  vector<T> arr;
};

template <typename T> void MinHeap<T>::insert(T key) {
  vector<T> &arr = this->arr;
  arr.push_back(key);
  size_t i = arr.size() - 1;
  size_t parent = (i - 1) / 2;
  while (i != 0 && arr[parent] > arr[i]) {
    swap(arr[parent], arr[i]);
    i = parent;
    parent = (i - 1) / 2;
  }
}

template <typename T> T MinHeap<T>::extract() {
  vector<T> &arr = this->arr;
  if (arr.size() < 1)
    return ~0;

  T res = arr[0];
  if (arr.size() == 1) {
    arr.erase(--arr.end());
    return res;
  }

  swap(arr[0], arr[arr.size() - 1]);
  arr.erase(--arr.end());
  size_t i = 0;
  size_t left_child = 2 * i + 1;
  size_t right_child = 2 * i + 2;

  while (true) {
    size_t min_index = i;

    if (left_child < arr.size() && arr[left_child] < arr[min_index]) {
      min_index = left_child;
    } else if (right_child < arr.size() && arr[right_child] < arr[min_index]) {
      min_index = right_child;
    }

    if (min_index == i)
      break;

    swap(arr[i], arr[min_index]);

    i = 2 * min_index;
    left_child = 2 * i + 1;
    right_child = 2 * i + 2;
  }

  return res;
}

int main() {
  MinHeap<int64_t> priorityQueue;
  priorityQueue.insert(40);
  priorityQueue.insert(30);
  priorityQueue.insert(10);
  priorityQueue.insert(100);
  priorityQueue.insert(50);
  priorityQueue.insert(15);
  priorityQueue.insert(40);
  cout << priorityQueue.extract() << priorityQueue.extract() << endl;
  return EXIT_SUCCESS;
}