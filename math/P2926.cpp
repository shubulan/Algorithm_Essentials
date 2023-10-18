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
/**
 *  n = 10^5  m = 10^6
 * 时间复杂度:O(n) + O(nlog(n))
 * 如果不去重，最坏情况下是O(nm)
 * 
 */
const int N = 1000005, M = 100005;
int arr[N]; // 记录有多少个数可以整除x
int arr2[N]; // x有多少个重复的
int nums[M], n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
    arr2[nums[i]]++;
  }
  for (int i = 0; i < N; i++) {
    if (!arr2[i]) continue;
    for (int t = i; t <= N; t += i) arr[t] += arr2[i];
  }

  for (int i = 0; i < n; i++) {
    printf("%d\n", arr[nums[i]] - 1);
  }

  return 0;
}