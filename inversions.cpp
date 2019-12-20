#include <bits/stdc++.h>

using namespace std;

size_t countSplitInversions(vector<uint32_t> &arr, size_t start, size_t mid,
                            size_t end) {
  vector<uint32_t> lArr = vector<uint32_t>(mid - start);
  vector<uint32_t> rArr = vector<uint32_t>(end - mid);

  for (auto i = 0; i < lArr.size(); i++)
    lArr[i] = arr[start + i];
  for (auto i = 0; i < rArr.size(); i++)
    rArr[i] = arr[mid + i];

  size_t count = 0;
  size_t left_ptr = 0, right_ptr = 0, arr_ptr = start;
  while (left_ptr < lArr.size() && right_ptr < rArr.size()) {
    if (lArr[left_ptr] < rArr[right_ptr]) {
      arr[arr_ptr++] = lArr[left_ptr++];
    } else {
      arr[arr_ptr++] = rArr[right_ptr++];
      count += lArr.size() - left_ptr;
    }
  }

  while (left_ptr < lArr.size()) {
    arr[arr_ptr++] = lArr[left_ptr++];
  }
  while (right_ptr < rArr.size()) {
    arr[arr_ptr++] = rArr[right_ptr++];
  }

  return count;
}

size_t countInversions(vector<uint32_t> &arr, size_t start, size_t end) {
  if (end - start < 2)
    return 0;

  size_t mid = start + (end - start) / 2;

  return countInversions(arr, start, mid) + countInversions(arr, mid, end) +
         countSplitInversions(arr, start, mid, end);
}

int main() {
  size_t constexpr n = 100000;
  vector<uint32_t> inputArray = vector<uint32_t>(n);
  for (auto &el : inputArray) {
    cin >> el;
  }
  cout << countInversions(inputArray, 0, n) << endl;
  return EXIT_SUCCESS;
}