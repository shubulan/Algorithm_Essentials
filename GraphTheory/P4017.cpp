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
const int N = 5005;
vector<int> G[N];
int ct[N], degree[N];
int n, m, res;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[b].push_back(a);
    degree[a]++;
  }
  queue<int> que;
  for (int i = 1; i <= n; i++) 
    if (degree[i] == 0) {
      que.push(i);
      ct[i] = 1;
    }
  
  while (!que.empty()) {
    int nd = que.front(); que.pop();
    if (G[nd].size() == 0) {
      res = (res + ct[nd]) % 80112002;
    }
    for (int j = 0; j < G[nd].size(); j++) {
      int ndd = G[nd][j];
      degree[ndd]--;
      ct[ndd] += ct[nd];
      ct[ndd] %= 80112002;
      if (degree[ndd] == 0) {
        que.push(ndd);
      }
    }
  }

  printf("%d", res);

  return 0;
}