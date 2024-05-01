#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
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
int n, m;
int vi[N], nx[N], e[N], h[N], idx;

void add(int a, int b) {
    e[idx] = b;
    nx[idx] = h[a];
    h[a] = idx++;
}

void bfs() {
  vi[1] = 0;
  queue<int> que;
  que.push(1);
  
  while (!que.empty()) {
    int r = que.front();
    que.pop();
    for (int i = h[r]; ~i; i = nx[i]) {
        int x = e[i];
        if (vi[x] != -1) continue;
        vi[x] = vi[r] + 1;
        que.push(x);
    }
  } 
}

int main() {
  cin >> n >> m;
  memset(vi, -1, sizeof vi);
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
  }
  bfs();
  cout << vi[n];

  return 0;
}