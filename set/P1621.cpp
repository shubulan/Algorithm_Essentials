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
typedef pair<int, int> PII;
/**
 * 知道线性筛，但是没做过筛法的题目。。
 * 先说复杂度：
 * 1. 枚举p到b之间的所有素数，
 * 2. 每次遍历<a... a + p, ...b>
 * 3. 合并操作
 * 设：n = b - a
 * 复杂度大致是nlog(n)log(n)，实际小于它，应该大致为nlog(n)
 * 因为合并操作基本不怎么耗时
 * 
 * 分析：
 * 容易知道是考察并查集
 * 暴力枚举：i, j，每次质因数分解，并且查询是否有公共的大于p的质数，然后合并。
 * 复杂度是O(n2 * logn)肯定过不去。且所有基于该思路的方法都过不去。
 *  比如说预处理提前质因数分解、维护集合内所有质因数等。
 * 筛法：
 * 既然分解质因数困难，不如反过来，对于质数x,我们可以很容易遍历它的所有倍数t,
 * t的约数就包含x。把所有的t合并起来即可。
 */


const int N = 100005;
int primes[N];
int cnt = 0;
int idx;

int a, b, p, res;
int par[N];


void init_prime(int n) {
  for (int i = 2; i <= n; i++) {
    if (!primes[i]) {
      primes[++cnt] = i;
      if (idx == 0 && i >= p) idx = cnt; // 找到第一个大于等于p的素数
    }
    for (int j = 1; primes[j] * i <= n; j++) {
      primes[primes[j] * i] = 1;
      if (i % primes[j] == 0) break;
    }
  }
}

int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  par[y] = x;
}

int main() {
  cin >> a >> b >> p;
  init_prime(max(a, b));
  for (int i = a; i <= b; i++) par[i] = i;
  for (int i = idx; i <= cnt; i++) {
    int t = primes[i];
    int x = a / t * t;
    for (int j = x; j <= b; j += t) {
      if (j < a || j - t < a) continue;
      unite(j, j - t);
    }
  }
  for (int i = a; i <= b; i++) {
    if (par[i] == i) res++;
  }
  cout << res << endl;
  return 0;
}