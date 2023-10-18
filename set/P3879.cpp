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