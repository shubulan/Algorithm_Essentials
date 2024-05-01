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

const int N = 505, M = 100005;
int h[N], e[M], nx[M], idx;
int ph[N];
bool st[N];
int n1, n2, m;
void add(int a, int b) {
    e[idx] = b;
    nx[idx] = h[a];
    h[a] = idx++;
}

bool find(int x) {
    // 递归终止条件是什么？
    for (int i = h[x]; ~i; i = nx[i]) {
        int p = e[i];
        if (st[p]) continue; // 已经心有所属
        st[p] = true; // 同意把对象换成 x，前提是我原对象能找到下家
        if (!ph[p] || find(ph[p])) {
            ph[p] = x;
            return true;
        }
    }
    st[x] = false;
    return false;
}

int hungary() {
    int cnt = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, false, sizeof st);
        if (find(i)) cnt++;
    }
    return cnt;
}

int main() {
  
  cin >> n1 >> n2 >> m;
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
  }

  int res = hungary();
  cout << res << endl;

  return 0;
}