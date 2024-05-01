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

const int N = 100005;
int arr[N];

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }

  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << arr[r] - arr[l - 1] << endl;
  }
  return 0;
}