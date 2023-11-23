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
typedef unsigned int uint;
typedef pair<int, int> PII;

unordered_map<uint, LL> mmap;
uint get(string s, string b) {
  const uint mod = 1e9 + 7;
  uint res = 1;
  res = res * mod + s[0];
  res = res * mod + s[1];
  res = res * mod + b[0];
  res = res * mod + b[1];
  return res;
}
int n;
char a[100], b[10];
int main() {
  scanf("%d", &n);
  LL res = 0;
  while (n--) {
    scanf("%s%s", a, b);
    if (a[0] == b[0] && a[1] == b[1]) continue;
    res += mmap[get(b, a)];
    mmap[get(a, b)]++;
  }
  printf("%lld\n", res);
  return 0;
}