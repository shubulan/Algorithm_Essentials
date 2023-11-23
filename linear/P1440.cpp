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
const int N = 2000005;
int arr[N];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  deque<int> que;
  for (int i = 0; i < n; i++) {
    if (que.empty())
      printf("0\n");
    else
      printf("%d\n", arr[que.front()]);
    while (!que.empty() && arr[que.back()] > arr[i]) que.pop_back();
    que.push_back(i);
    while (que.front() <= i - m) que.pop_front();
  }
  return 0;
}