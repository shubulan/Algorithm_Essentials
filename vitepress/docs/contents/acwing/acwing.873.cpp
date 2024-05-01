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

int phi(int x) {
    int y = x;
    vector<int> p;
    for (int i = 2; i <= x / i; i++) {
        int t = 0;
        while (x % i == 0) {
            t++;
            x /= i;
        }
        if (t) p.push_back(i);
    }
    if (x > 1) p.push_back(x);
    for (int i = 0; i < p.size(); i++) {
        y /= p[i];
        y *= (p[i] - 1);
    }
    return y;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    cout << phi(x) << endl;
  }
  return 0;
}