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

#define MAX_N
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int n;
  cin >> n;
  vector<LL> arr;
  for (int i = 0, t; i < n; i++) {
      cin >> t;
      arr.push_back(t);
  }
  sort(arr.begin(), arr.end());
  LL mx = -1;
  for (int i = 0; i < n; i++) {
      mx = max(mx, arr[i] * (n - i));
  }
  for (int i = 0; i < n; i++) {
      if (mx == arr[i] * (n - i)) {
          cout << mx << " " << arr[i] << endl;
          break;
      }
  }

  return 0;
}
