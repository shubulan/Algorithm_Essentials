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
int p[N], cnt, phi[N];
bool st[N];

void get_phi(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!st[i]) {
        p[cnt++] = i;
        phi[i] = i - 1;
    }
    for (int j = 0; p[j] <= n / i; j++) {
        st[p[j] * i] = true;
        if (i % p[j]) {
            phi[p[j] * i] = phi[i] * (p[j] - 1);
        } else {
            phi[p[j] * i] = phi[i] * p[j];
            break;
        }
    }
  }

}

int main() {
  int n;
  cin >> n;
  get_phi(n);
  LL res = 0; // 可能溢出
  for (int i = 1; i <= n; i++) {
    res += phi[i];
  }
  cout << res << endl;
  return 0;
}