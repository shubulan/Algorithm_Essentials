#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

/**
 * 正整数加法
*/
vector<int> add(const vector<int>& A, const vector<int> &B) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size() || i < B.size(); i++) {
    if (i < A.size()) t += A[i];
    if (i < B.size()) t += B[i];
    C.push_back(t % 10);
    t /= 10;
  }
  if (t) C.push_back(t);
  return C;
}

int main() {
  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  vector<int> x, y;
  for (auto c : a) x.push_back(c - '0');
  for (auto c : b) y.push_back(c - '0');
  vector<int> res = add(x, y);
  reverse(res.begin(), res.end());
  for (auto i : res) cout << i;
  cout << endl;
  return 0;
}