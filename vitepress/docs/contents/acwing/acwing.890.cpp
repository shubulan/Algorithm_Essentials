0


#include <iostream>

using namespace std;

int arr[20];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> arr[i];
  int res = 0;
  for (int i = 1; i < 1 << m; i++) {
    int x = n, d = -1;
    for (int j = 0; j < m; j++) {
      if (1 & (i >> j)) {
        d = -d;
        x /= arr[j];
      }
    }
    res += d * x;
  }
  cout << res << endl;


  return 0;
}