#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 200005;
int arr[N];
int cnt = 0;
int T, n;

void solve() {
  scanf("%d", &n);
  fill(arr, arr + n + 5, 0);
  cnt = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt++;
    arr[cnt + 1]--;
    int b = max(0, cnt + 1 - a);
    arr[b]++;
  }
  for (int i = 1; i <= n; i++) {
    arr[i] += arr[i - 1];
    printf("%d ", arr[i] > 0);
  }
  printf("\n");
}
int main() {
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}