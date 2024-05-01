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
vector<PII> arr;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    arr.push_back({a, b});
  }
  sort(arr.begin(), arr.end());
  int cnt = 0;
  for (int i = 0, j = 0; i < n; i++, i = j) {
    int r = arr[i].second;
    while (j < n && arr[j].first <= r) {
      r = max(r, arr[j].second);
      j++;
    }
    cnt++;
  }
  cout << cnt << endl;

  return 0;
}