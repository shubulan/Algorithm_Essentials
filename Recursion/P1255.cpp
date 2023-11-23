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

#define MAX_N 5000
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL arr[MAX_N + 5];

LL dfs(int n) {
  if (n == 0) return 1;
  if (n < 0) return 0;
  if (arr[n] != 0) return arr[n];
  return arr[n] = dfs(n - 1) + dfs(n - 2);
}
vector<int> add(const vector<int>& A, const vector<int>& B) {
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
  vector<int> a = vector<int>{1};
  vector<int> b = vector<int>{1};
  vector<int> c{1};
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    c = add(a, b);
    // a = std::move(b);
    // b = std::move(c);
    a = b;
    b = c;
  }
  for (int i = b.size() - 1; i >= 0; i--) cout << b[i];
  cout << endl;
  return 0;
}
