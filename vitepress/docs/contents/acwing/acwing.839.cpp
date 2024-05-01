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

int ph[N], h[N], hp[N], idx, cnt;

void heap_swap(int x, int y) {
    swap(ph[hp[x]], ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(h[x], h[y]);
}

void up(int i) {
    while ((i / 2) && h[i] < h[i / 2]) {
        heap_swap(i / 2, i);
        i /= 2;
    }
}

void down(int u) {
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (t != u) {
        heap_swap(u, t);
        down(t);
    }
}

void insert(int x) {
    ++cnt, ++idx;
    ph[idx] = cnt;
    h[cnt] = x;
    hp[cnt] = idx;

    up(cnt);
}

int top() {
    return h[1];
}

void remove(int k) {
    int t = ph[k];
    heap_swap(cnt--, ph[k]);
    up(t);
    down(t);
}

void pop() {
    heap_swap(1, cnt--);
    down(1);
}

void modify(int k, int x) {
    h[ph[k]] = x;
    up(ph[k]);
    down(ph[k]);
}

int main() {
  int m;
  cin >> m;
  while (m--) {
    string op;
    cin >> op;
    int x, y, z;
    if (op == "I") {
        cin >> x;
        insert(x);
    } else if (op == "PM") {
        cout << top() << endl;
    } else if (op == "D") {
        cin >> x;
        remove(x);
    } else if (op == "C") {
        cin >> x >> y;
        modify(x, y);
    } else if (op == "DM") {
        pop();
    }

  }

  return 0;
}