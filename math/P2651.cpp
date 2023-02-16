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
const int N = 10005;
int t, n;
int arr[N];
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  int x = arr[0];
  int i = 2;
  while (arr[1] && i <= n) {
    int t = gcd(x, arr[1]);
    arr[1] /= t;
    if (arr[1] == 1) break;
    x = arr[i];
    i++;
  }
  if (arr[1] == 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}