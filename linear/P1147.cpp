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

int m;
vector<PII> arr;
void check(int a, int b) {
  int k = (b - a + 1);
  if (k < 0 || k % 2) return;
  arr.push_back({k / 2, k / 2 + a - 1});
}
int main() {
  scanf("%d", &m);
  // m *= 2;
  // for (int i = 2; i * i <= m; i++) {
  //   if (m % i) continue;
  //   check(i, m / i);
  // }
  // sort(arr.begin(), arr.end());
  // for (auto &pii:arr) {
  //   printf("%d %d\n", pii.first, pii.second);
  // }
  // 双指针
  LL sum = 0;
  for (int i = 1, j = 1; i < m; i++) {
    while (j <= m && sum < m) sum += j, j++;
    if (sum == m) printf("%d %d\n", i, j - 1);
    sum -= i;
  }
  return 0;
}