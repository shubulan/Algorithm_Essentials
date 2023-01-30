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
const int N = 5000;
int par[N + 5];

int find(int a) {
  if (par[a] != a) {
    par[a] = find(par[a]);
  }
  return par[a];
}

void Union(int a, int b) {
  int x = find(a);
  int y = find(b);
  par[x] = y;
}

int main() {
  int n, m, p;
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 0; i <= n; i++ ) par[i] = i;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    Union(a, b);
  }
  for (int i = 0; i < p; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%s\n", find(a) == find(b) ? "Yes" : "No");
  }


  return 0;
}