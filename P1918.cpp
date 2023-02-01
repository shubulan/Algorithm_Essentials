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