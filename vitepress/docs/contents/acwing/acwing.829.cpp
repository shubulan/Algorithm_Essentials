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

int q[N], h, t;
void push(int x) { q[t++] = x; }
void pop() { h++; }
int query() { return q[h]; }
int empty() { return t == h; }
int main() {
  int m;
  cin >> m;
  while (m--) {
    string s;
    cin >> s;
    if (s == "push") {
      int x;
      cin >> x;
      push(x);
    } else if (s == "pop") {
      pop();
    } else if (s == "empty") {
      cout << (empty() ? "YES" : "NO") << endl;
    } else {
      cout << query() << endl;
    }
  }

  return 0;
}