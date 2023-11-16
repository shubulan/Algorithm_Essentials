#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 100005;
int n, k;
int a[N];

int main() {
  scanf("%d%d", &n, &k);
  a[0] = 1;
  int res = 0;
  while (k--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (!a[y]) res++;
    a[x] = 1;
  }
  printf("%d\n", res);

  return 0;
}
