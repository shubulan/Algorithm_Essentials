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

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int r = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return r;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b, m, x, y;
    cin >> a >> b >> m;
    int r = exgcd(a, m, x, y);
    if (b % r) cout << "impossible" << endl;
    else cout << (LL)x * b / r % m << endl;
  }
  return 0;
}