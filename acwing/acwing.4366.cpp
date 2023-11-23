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

#define MAX_N 100000
int arr[MAX_N + 5];

bool check(int *arr, int n, int cp) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += arr[i];
    if (res > cp) return false;
    if (res == cp) res = 0;
  }
  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int sum = 0, mx = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d", arr + i);
      sum += arr[i];
    }

    if (sum == 0) {
      printf("%d\n", 0);
      continue;
    }

    for (int i = 1; i <= sum; i++) {
      if (sum % i != 0) continue;
      if (check(arr, n, i)) {
        printf("%d\n", n - sum / i);
        break;
      }
    }
  }
  return 0;
}
