#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

/**
 * 证明该排序是最大值
 * 该排序的结果是任何i < j
 * s[i] + s[j] >= s[j] + s[i]
 * 如果某最优解不满足该不等式，那么我们可以通过交换二者的顺序
 * 使整体的字典序列更大，从而获得更大的值。这与最优解矛盾，成立。
 */

int main() {
  string s;
  int n;
  cin >> n;
  vector<string> arr;
  for (int i = 0; i < n; i++) {
    cin >> s;
    arr.push_back(s);
  }
  sort(arr.begin(), arr.end(),
       [](string &a, string &b) { return a + b > b + a; });
  string res;
  for (auto &s : arr) res += s;
  cout << res << endl;
  return 0;
}