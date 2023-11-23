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
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;
int arr[N], b[N];

void insert(int l, int r, int c) {
  b[l] += c;
  b[r + 1] -= c;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = n; i >= 1; i--) {  // 这里可以用差分，也可以用插入
    // arr[i] -= arr[i - 1];
    insert(i, i, arr[i]);
  }

  while (m--) {
    int l, r, c;
    cin >> l >> r >> c;
    insert(l, r, c);
    // arr[l] += c;
    // arr[r + 1] -= c;
  }
  // for (int i = 1; i <= n; i++) arr[i] += arr[i - 1];
  for (int i = 1; i <= n; i++) b[i] += b[i - 1];
  for (int i = 1; i <= n; i++) {
    // cout << arr[i] << " ";
    cout << b[i] << " ";
  }
  cout << endl;

  return 0;
}