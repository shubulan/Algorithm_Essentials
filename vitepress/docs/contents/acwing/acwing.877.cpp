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
    int a, b, x, y;
    cin >> a >> b;
    exgcd(a, b, x, y);
    cout << x << " " << y << endl;
  }

  return 0;
}