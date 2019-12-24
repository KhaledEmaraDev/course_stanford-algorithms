#include "min-heap.hpp"
#include <iostream>

using namespace std;

int main() {
  MinHeap<int64_t> priorityQueue{40, 30, 10, 100, 50, 15};
  priorityQueue.insert(40);
  priorityQueue.erase(0);
  priorityQueue.decrease(0, 5);
  cout << priorityQueue.pop() << " " << priorityQueue.top() << endl;
  return EXIT_SUCCESS;
}