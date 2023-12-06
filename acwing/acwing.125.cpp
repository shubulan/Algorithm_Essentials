#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;
typedef long long LL;

const int N = 50005;
PII arr[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int w, s;
    cin >> w >> s;
    arr[i] = {w + s, s};
  }
  sort(arr, arr + n);
  LL cnt = 0, res = -0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    res = max(res, cnt - arr[i].second);
    cnt += arr[i].first - arr[i].second;
  }
  cout << res << endl;

  return 0;
}