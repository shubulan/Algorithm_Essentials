```c++
#include <iostream>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;

int heap[N], n, m;

void down(int x) {
    int u = -1;
    while (u != x) {
        u = x;
        int L = u * 2, R = u * 2 + 1;
        if (L <= n && heap[L] < heap[x]) x = L;
        if (R <= n && heap[R] < heap[x]) x = R;
        if (x != u) swap(heap[x], heap[u]);
    }
}

int top() {
    return heap[1];
}

void pop() {
    swap(heap[1], heap[n--]);
    down(1);
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> heap[i];
  for (int i = n / 2; i; i--) down(i);
  
  for (int i = 0; i < m; i++) {
    cout << top() << " ";
    pop();
  }

  return 0;
}
```