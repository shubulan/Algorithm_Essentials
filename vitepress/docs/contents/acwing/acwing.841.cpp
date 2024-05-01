#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int N = 100005, P = 13331;
typedef unsigned long long ULL;

ULL h[N], p[N];
ULL get(int l, int r) {
  return h[r] - h[l - 1] * p[r - l + 1];
}
int main() {
  string s;
  int n, m;
  cin >> n >> m;
  cin >> s;
  p[0] = h[0] = 1;
  for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] * P + s[i - 1];
    p[i] = p[i - 1] * P;
  }
  while (m--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (get(a, b) == get(c, d)) puts("Yes");
    else puts("No");
  }

  return 0;
}