#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

const int MAX_N = 1;
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

set<int> sset;
int n, a, b;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    if (a == 1) {
      if (sset.count(b))
        printf("Already Exist\n");
      else
        sset.insert(b);
    } else {
      if (sset.size() == 0)
        printf("Empty\n");
      else {
        auto it = sset.lower_bound(b);
        if (it == sset.end()) {
          --it;
          printf("%d\n", *it);
          sset.erase(it);
        } else if (sset.size() == 1) {
          it == sset.begin();
          printf("%d\n", *it);
          sset.erase(it);
        } else if (it == sset.begin()) {
          printf("%d\n", *it);
          sset.erase(it);
        } else {
          if (*it == b)
            printf("%d\n", *it);
          else {
            auto it2 = it;
            it2--;
            if (b - *it2 <= *it - b) it = it2;
            printf("%d\n", *it);
          }
          sset.erase(it);
        }
      }
    }
  }
  return 0;
}