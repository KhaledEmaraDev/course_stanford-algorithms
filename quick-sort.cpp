#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> arr) {
  for (auto el : arr)
    cout << el << " ";
}

size_t partition(vector<int64_t> &arr, size_t start, size_t end, size_t pivot) {
  if (pivot != start)
    swap(arr[pivot], arr[start]);

  int64_t pivotElement = arr[pivot];

  size_t i = start;
  for (auto j = start + 1; j < end; j++)
    if (arr[j] < pivotElement)
      swap(arr[j], arr[++i]);

  swap(arr[start], arr[i]);
  return i;
}

size_t qsort(vector<int64_t> &arr, size_t start, size_t end) {
  if (end - start < 2)
    return 0;

  size_t numComparisons = 0;

  size_t partitionIndex = partition(arr, start, end, end - 1);
  numComparisons += qsort(arr, start, partitionIndex);
  numComparisons += qsort(arr, partitionIndex + 1, end);

  return numComparisons + end - start - 1;
}

int main() {
  size_t constexpr n = 10000;
  vector<int64_t> inputArray = vector<int64_t>(n);
  for (auto &el : inputArray) {
    cin >> el;
  }
  cout << qsort(inputArray, 0, n) << endl;
  return EXIT_SUCCESS;
}