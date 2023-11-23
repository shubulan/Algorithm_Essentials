#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

unordered_map<string, set<int>> mmap;
int t, n;

int main() {
  scanf("%d", &t);
  int i = 1;
  while (t--) {
    scanf("%d", &n);
    string s;
    while (n--) {
      cin >> s;
      mmap[s].insert(i);
    }
    i++;
  }
  scanf("%d", &t);
  while (t--) {
    string s;
    cin >> s;
    for (auto &x : mmap[s]) {
      printf("%d ", x);
    }
    printf("\n");
  }

  return 0;
}