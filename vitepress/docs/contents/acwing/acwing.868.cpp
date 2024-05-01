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

const int N = 1000005;
int p[N], cnt;
bool st[N];

void get_primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (!st[i]) p[cnt++] = i;

    for (int j = 0; p[j] <= n / i; j++) {
        st[p[j] * i] = true;
        if (i % p[j] == 0) break;
    }
  }
}


int main() {
  int n;
  cin >> n;
  get_primes(n);
  cout << cnt << endl;
  // for (int i = 0; i < cnt; i++) {
  //   cout << p[i] << " ";
  // }

  return 0;
}