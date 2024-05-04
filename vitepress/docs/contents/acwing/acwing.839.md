::: code-group
```c++ [堆模板]
// 堆从 1 开始索引
// 小顶堆
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
// 不常用
void up(int x) {
    while ((x / 2) && heap[x] < h[x / 2]) {
        swap(heap[x / 2], heap[x]);
        x /= 2;
    }
}

// 堆化
for (int i = n / 2; i; i--) down(i);

// 获取堆顶

int top() {
    return heap[1];
}

```
```c++ [可更新堆]
#include <iostream>

using namespace std;

const int N = 100005;

/**
    ph: key 到 h 中索引的映射
    h:  堆本身，存 value
    hp: 堆的伴随数组，存储 key
*/
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

void down(int x) {
    int u = -1;
    while (u != x) {
        u = x;
        int L = u * 2, R = u * 2 + 1;
        if (L <= cnt && h[L] < h[x]) x = L;
        if (R <= cnt && h[R] < h[x]) x = R;
        if (x != u) heap_swap(x, u);
    }
}

void insert(int x) { // 增
    ++cnt, ++idx;
    ph[idx] = cnt;
    h[cnt] = x;
    hp[cnt] = idx;

    up(cnt);
}

int top() { // 查
    return h[1];
}

void remove(int k) { // 删
    int t = ph[k];
    heap_swap(cnt--, ph[k]);
    up(t);
    down(t);
}

void pop() { // 删
    heap_swap(1, cnt--);
    down(1);
}

void modify(int k, int x) { // 改
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
```
:::