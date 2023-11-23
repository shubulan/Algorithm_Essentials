#include <algorithm>
#include <cassert>
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
typedef pair<int, int> PII;

const int N = 100005;

int p[N], sz[N];

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  p[x] = y;
  sz[y] += sz[x];
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) p[i] = i, sz[i] = 1;

  while (m--) {
    string op;
    int x, y; 
    cin >> op;
    if (op == "C") {
      cin >> x >> y;
      unite(x, y);
    } else if (op == "Q1") {
      cin >> x >> y;
      cout << (find(x) == find(y) ? "Yes" : "No") << endl;
    } else if (op == "Q2") {
      cin >> x;
      cout << sz[find(x)] << endl;
    }
  }


  return 0;
}