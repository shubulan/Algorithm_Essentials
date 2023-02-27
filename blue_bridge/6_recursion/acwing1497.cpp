#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 200005;
struct node{
    int v;
    node *l, *r;
};
int a[N], b[N];
int n;


node * dfs(int *a, int al, int ar, int *b, int bl, int br) {
    if (al > ar) return nullptr;
    int k = a[ar];
    int j = bl;
    for (; j <= br; j++) {
        if (b[j] == k) break;
    }
    int len = j - bl;
    node *l = dfs(a, al, al + len - 1, b, bl, j - 1);
    node *r = dfs(a, al + len, ar - 1, b, j + 1, br);
    node *root = new node;
    root->v = k;
    root->l = l;
    root->r = r;
    return root;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  node * root = dfs(a, 0, n - 1, b, 0, n - 1);
  queue<node *> que;
  que.push(root);
  while (!que.empty()) {
      node *c = que.front(); que.pop();
      printf("%d ", c->v);
      if (c->l) que.push(c->l);
      if (c->r) que.push(c->r);
  }
  printf("\n");


  return 0;
}
