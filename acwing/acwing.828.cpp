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

int st[N], top = -1;

void push(int x) { st[++top] = x; }

void pop() { top--; }

int query() { return st[top]; }

int empty() { return top == -1; }

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "push") {
      int x;
      cin >> x;
      push(x);
    } else if (s == "query") {
      cout << query() << endl;
    } else if (s == "pop")
      pop();
    else if (s == "empty")
      cout << (empty() ? "YES" : "NO") << endl;
  }

  return 0;
}