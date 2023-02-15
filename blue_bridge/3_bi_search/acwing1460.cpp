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
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int N = 105;
const int B = 1e9 + 7;
int n;
ULL h[105], T[105];
string s;
bool check(int m) {
  unordered_map<ULL, int> mmap;
  ULL a = 0;
  ULL t = T[m];;
  for (int i = m; i <= n; i++) {
    if (i == m) a = h[i];
    else a = a * B + s[i - 1] - s[i - 1 - m] * t;
    if (mmap.count(a)) return false;
    mmap[a]++;
  }
  return true;
}
void init() {
  T[0] = 1;
  for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] * B + s[i - 1];
    T[i] = T[i - 1] * B;
  }
}
int main() {
  cin >> n;
  cin >> s;
  init();
  int l = 1, r = n;  
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}