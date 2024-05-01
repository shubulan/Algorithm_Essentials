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

int qmi(LL a, int b, int p) {
    LL res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, p;
    cin >> a >> p;
    // 无需考虑 2 为什么？
    if (a % p == 0) cout << "impossible" << endl;
    else cout << qmi(a, p - 2, p) << endl;
  }
  return 0;
}