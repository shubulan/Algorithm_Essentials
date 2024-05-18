```c++
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

const int N = 1005;
int arr[N][N];

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      arr[i][j] += (arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]);
    }
  }
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] +
                arr[x1 - 1][y1 - 1]
         << endl;
  }

  return 0;
}
```