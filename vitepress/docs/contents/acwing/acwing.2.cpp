#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;
int f[N];

int main()
{
    int n, V;
    cin >> n >> V;
    f[0] = 0;
    while (n--) {
      int v, w;
      cin >> v >> w;
      for (int i = V; i >= v; i--) {
        f[i] = max(f[i], f[i - v] + w);
      }
    }
    int mx = 0;
    for (int i = 0; i <= V; i++) mx = max(mx, f[i]);
    cout << mx << endl;
    return 0;
}