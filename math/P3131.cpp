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
const int MAX_N = 50005;
int s[MAX_N];
int mem[10];
int n;
int main() {
  scanf("%d", &n);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
    s[i] += s[i - 1];
    s[i] %= 7;
    if (!mem[s[i]] && s[i] != 0) mem[s[i]] = i;
    if (i - mem[s[i]] > res) {
      res = i - mem[s[i]];
    }
  }
  printf("%d\n", res);


  return 0;
}