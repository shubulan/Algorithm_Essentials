#include <algorithm>
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

int n, m;
int main() {
  scanf("%d%d", &n, &m);
  LL c = 1, pre = 0;
  while (n--) {
    int a;
    scanf("%d", &a);
    LL tc = c;
    c *= a;
    LL b = m % c - pre;
    printf("%lld ", b / tc);
    pre += b;
  }
  printf("\n");
  return 0;
}
