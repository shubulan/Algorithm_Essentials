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

void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        int t = 0;
        while (x % i == 0) {
            t++;
            x /= i;
        }
        if (t) {
            cout << i << " " << t << endl;
        }
    }
    if (x > 1) {
        cout << x << " " << 1 << endl;
    }
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    divide(a);
    cout << endl;
  }
  return 0;
}