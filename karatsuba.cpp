#include <bits/stdc++.h>

using namespace std;

string add(string num1, string num2) {
  stack<char> res;
  int64_t first_ptr = num1.length() - 1, second_ptr = num2.length() - 1;
  int8_t rem = 0;
  while (first_ptr >= 0 || second_ptr >= 0) {
    int8_t first_num = first_ptr >= 0 ? num1[first_ptr] - '0' : 0,
           second_num = second_ptr >= 0 ? num2[second_ptr] - '0' : 0;
    int8_t ans = first_num + second_num + rem;
    if (rem > 0)
      rem--;
    if (ans > 9) {
      rem++;
      ans -= 10;
    }
    res.push(ans + '0');
    first_ptr--;
    second_ptr--;
  }
  if (rem > 0)
    res.push('1');

  string ans;
  ans.reserve(res.size());
  while (!res.empty()) {
    ans.push_back(res.top());
    res.pop();
  }

  return ans;
}

string multiply(string num1, string num2) {
  int64_t n = num1.length();
  int64_t mid = n / 2;
  if (n == 1) {
    int8_t first_num = num1[0] - '0', second_num = num2[0] - '0';
    return to_string(first_num * second_num);
  }
  string a = num1.substr(0, mid);
  string b = num1.substr(mid, mid);
  string c = num2.substr(0, mid);
  string d = num2.substr(mid, mid);
  string ac = multiply(a, c);
  string bd = multiply(b, d);
  return add(add(ac + string(n, '0'),
                 add(multiply(a, d), multiply(b, c)) + string(mid, '0')),
             bd);
}

int main() {
  cout
      << multiply(
             "3141592653589793238462643383279502884197169399375105820974944592",
             "2718281828459045235360287471352662497757247093699959574966967627")
      << endl;
  return EXIT_SUCCESS;
}
