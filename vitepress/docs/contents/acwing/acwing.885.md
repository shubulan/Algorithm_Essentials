```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2005, mod = 1e9 + 7;
int c[N][N];
typedef long long LL;

int n;
void init(int n) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (!j) c[i][j] = 1;
      else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }
}
int main() {
  cin >> n;
  init(2000);
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << c[a][b] << endl;
  }
  return 0;
}
```