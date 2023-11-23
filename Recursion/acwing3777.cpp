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
const int N = 205;
int t, n;
char arr[N], arr2[N];
int ops[N];

void print() {
  int ct = 0;
  for (int i = 0; i < n; i++) {
    if (ops[i] == 1) {
      ops[ct++] = i + 1;
    }
  }
  printf("%d\n", ct);
  if (ct == 0) return;
  for (int i = 0; i < ct; i++) {
    printf("%d ", ops[i]);
  }
  printf("\n");
  return;
}
void solve() {
  scanf("%d", &n);
  scanf("%s", arr);
  for (int i = 0; i < n; i++) {
    arr2[i] = arr[i];
  }
  memset(ops, 0, sizeof ops);
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == 'W') continue;
    arr[i] = 'B';
    ops[i] = 1;
    if (arr[i + 1] == 'B')
      arr[i + 1] = 'W';
    else
      arr[i + 1] = 'B';
  }
  if (arr[n - 1] == 'W') {
    print();
    return;
  }
  memset(ops, 0, sizeof ops);
  for (int i = 0; i < n - 1; i++) {
    if (arr2[i] == 'B') continue;
    arr[i] = 'W';
    if (arr2[i + 1] == 'B')
      arr2[i + 1] = 'W';
    else
      arr2[i + 1] = 'B';
  }
  if (arr2[n - 1] == 'B') {
    print();
    return;
  }
  printf("-1\n");
  return;
}
int main() {
  scanf("%d\n", &t);
  while (t--) {
    solve();
  }

  return 0;
}