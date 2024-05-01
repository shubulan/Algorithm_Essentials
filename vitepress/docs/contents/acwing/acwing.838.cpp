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

int a[N], n, m;

void down(int x) {
    while (true) {
        int c = x;
        if (x * 2 <= n && a[x * 2] < a[c]) {
            c = x * 2;
        }
        if (x * 2 + 1 <= n && a[x * 2 + 1] < a[c]) {
            c = x * 2 + 1;
        }
        if (x != c) {
            swap(a[x], a[c]);
            x = c;
        } else break;

    }
}

int top() {
    return a[1];
}

void pop() {
    swap(a[1], a[n--]);
    down(1);
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = n / 2; i; i--) down(i);
  
  for (int i = 0; i < m; i++) {
    cout << top() << " ";
    pop();
  }

  return 0;
}