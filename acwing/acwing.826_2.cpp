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

// 0 号位置默认头结点写法
int head, e[N], nx[N], cnt;

void insert(int x, int k) {
  e[++cnt] = x;
  nx[cnt] = nx[k];
  nx[k] = cnt;
}

void erase(int k) { nx[k] = nx[nx[k]]; }

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'H') {
      int x;
      cin >> x;
      insert(x, 0);
    } else if (c == 'D') {
      int k;
      cin >> k;
      erase(k);
    } else if (c == 'I') {
      int k, x;
      cin >> k >> x;
      insert(x, k);
    }
  }
  for (int i = nx[head]; i; i = nx[i]) {
    cout << e[i] << " ";
  }
  cout << endl;

  return 0;
}