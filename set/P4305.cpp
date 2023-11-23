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

const int N = 50005;
int arr[N], cnt, t, n;
unordered_map<int, int> mmap;
int main() {
  scanf("%d", &t);

  while (t--) {
    mmap.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
      if (mmap.count(arr[i])) continue;
      printf("%d ", arr[i]);
      mmap[arr[i]]++;
    }
    printf("\n");
  }

  return 0;
}