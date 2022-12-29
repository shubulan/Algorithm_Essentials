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

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

#define MAX_N 1000
int arr[MAX_N + 5];
int dfs(int n) {
  if (arr[n] != 0) return arr[n];
  int res = 1;
  for (int i = 1; i <= n / 2; i++) {
    res += dfs(i);
  }
  return arr[n] = res;
}

int main() {
  string s;
  LL t;
  cin >> s >> t;
  int n = s.size();
  while (t > n) {
      //cout << t << endl;
      LL x = n;
      while (x < t) {
          x *= 2;
      }
      LL md = x / 2;
      t -= md;
      t = (t - 1);
      if (t <= 0) t = md;
  }
  cout << s[t - 1] << endl;

  return 0;
}
