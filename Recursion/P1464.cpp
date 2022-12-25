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

LL get(LL a, LL b, LL c) {
  return a * 10000 + b * 100 + c;
}
unordered_map<LL, LL> vis;

LL dfs(LL a, LL b, LL c) {
  if (a <= 0 || b <= 0 || c <= 0) return 1;
  if (a > 20 || b > 20 || c > 20) return dfs(20, 20, 20);
  if (vis.count(get(a, b, c))) {
    return vis[get(a, b, c)];
  }
  return vis[get(a, b, c)] = (dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + 
            dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1));

}
int main() {
  LL a, b, c;
  while (cin >> a >> b >> c) {
    if (a == -1 && b == -1 && c == -1) break;
    printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, dfs(a, b, c));
  }

  return 0;
}