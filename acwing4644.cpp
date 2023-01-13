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

typedef long long LL;

const int N = 200005;
int n;
LL res, sum;

int arr[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    res += arr[i] * sum;
    sum += arr[i];
  }
  printf("%lld\n", res);

  return 0;
}
