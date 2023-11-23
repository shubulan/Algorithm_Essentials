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

const int MAX_N = 100000;
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  unordered_map<int, int> mmap;
  int n, m, a;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    mmap[a] = i;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a);
    printf("%d\n", mmap[a]);
  }

  return 0;
}