#include <iostream>

using namespace std;

const int N = 105;

int f[N];
int vv[N], ww[N];

int main() {
  int n, V;
  cin >> n >> V;
  while (n--) {
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) cin >> vv[i] >> ww[i];

    for (int i = V; i >= 0; i--) {
      for (int j = 0; j < s; j++) {
        if (i - vv[j] < 0) continue;
        f[i] = max(f[i], f[i - vv[j]] + ww[j]);
      }
    }
  }
  cout << f[V] << endl;

  return 0;
}