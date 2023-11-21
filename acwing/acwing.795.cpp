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