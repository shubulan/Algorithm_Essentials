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
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;
int arr[N];

int main() {
  int n, res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  unordered_map<int, int> mp;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && mp[arr[j]] == 0) mp[arr[j++]]++;
    res = max(res, j - i);
    mp[arr[i]]--;
  }
  cout << res << endl;

  return 0;
}