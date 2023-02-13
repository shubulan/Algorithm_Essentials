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
const int N = 1000005;
int arr[N];
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  deque<int> que1, que2;
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  for (int i = 0; i < n; i++) {
    while (!que1.empty() && arr[que1.back()] > arr[i]) que1.pop_back();
    que1.push_back(i);
    if (i < k - 1) continue;
    while (que1.front() <= i - k) que1.pop_front();
    printf("%d ", arr[que1.front()]);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    while (!que2.empty() && arr[que2.back()] < arr[i]) que2.pop_back();
    que2.push_back(i);
    if (i < k - 1) continue;
    while (que2.front() <= i - k) que2.pop_front();
    printf("%d ", arr[que2.front()]);
  }
  printf("\n");
  return 0;
}