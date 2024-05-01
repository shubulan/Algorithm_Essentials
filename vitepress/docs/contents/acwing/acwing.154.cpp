#include <algorithm>
#include <cassert>
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

const int N = 100005;

int arr[N];
int main() {
  int n, k;
  cin >> n >> k;
  deque<int> q1, q2;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    while (!q2.empty() && arr[q2.back()] >= arr[i]) q2.pop_back();
    q2.push_back(i);
    while (i - q2.front() + 1 > k) q2.pop_front();
    if (i >= k - 1) cout << arr[q2.front()] << " ";
  }

  cout << endl;
  for (int i = 0; i < n; i++) {
    while (!q1.empty() && arr[q1.back()] <= arr[i]) q1.pop_back();
    q1.push_back(i);
    while (i - q1.front() + 1 > k) q1.pop_front();
    if (i >= k - 1) cout << arr[q1.front()] << " ";
  }
  cout << endl;

  return 0;
}