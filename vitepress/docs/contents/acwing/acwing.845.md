```c++
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
unordered_map<string, bool> st;
string s;
void bfs() {
  st[s] = true;
  queue<string> que;
  que.push(s);
  int t = 0;
  while (!que.empty()) {
    int sz = que.size();
    for (int i = 0; i < sz; i++) {
      string g = que.front();
      que.pop();
      if (g == "12345678x") {
        cout << t << endl;
        return;
      }
      int px = 0;
      for (; px < s.size(); px++) 
        if (g[px] == 'x') break;

      // try left
      if (px != 0 && px != 3 && px != 6) {
        string ng = g;
        swap(ng[px], ng[px - 1]);
        if (!st[ng]) {
          st[ng] = true;
          que.push(ng);
        }
      }
      // try up
      if (px >= 3) {
        string ng = g;
        swap(ng[px], ng[px - 3]);
        if (!st[ng]) {
          st[ng] = true;
          que.push(ng);
        }
      }

      // try right
      if (px != 2 && px != 5 && px != 8) {
        string ng = g;
        swap(ng[px], ng[px + 1]);
        if (!st[ng]) {
          st[ng] = true;
          que.push(ng);
        }
      }
      // try down
      if (px <= 5) {
        string ng = g;
        swap(ng[px], ng[px + 3]);
        if (!st[ng]) {
          st[ng] = true;
          que.push(ng);
        }
      }
    }
    t++;
  }
  cout << -1 << endl;
  return;
}

int main() {
  for (int i = 0; i < 9; i++) {
    char c;
    cin >> c;
    s += c;
  }
  bfs();

  return 0;
}
```