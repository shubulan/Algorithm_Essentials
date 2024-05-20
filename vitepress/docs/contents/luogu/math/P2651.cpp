#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 10005;
int t, n;
int arr[N];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
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