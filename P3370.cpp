#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;
typedef unsigned int uint;
typedef pair<int, int> PII;

unordered_set<uint> sset;
uint get(char* str) {
  const int P = 1e7 + 9;
  uint res = 1;
  for (char* p = str; *p; p++) {
    res = res * P + *p;
  }
  return res;
}
char s[2046];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    sset.insert(get(s));
  }
  printf("%u\n", sset.size());

  return 0;
}