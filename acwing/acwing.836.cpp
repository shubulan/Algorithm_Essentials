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

int p[N];

int find(int a) {
  return p[a] == a? a : p[a] = find(p[a]);
}

void unite(int a, int b) {
  a = find(a), b = find(b);
  p[a] = b;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) p[i] = i;
  while (m--) {
    string op;
    int a, b;
    cin >> op >> a >> b;
    if (op == "M") unite(a, b);
    else cout << (find(a) == find(b) ? "Yes" : "No") << endl;;
  }

  return 0;
}