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
using namespace std;
typedef long long LL;
const int N = 2005;
int f[N];
int main() {
    int n, V;
    cin >> n >> V;
    while (n--) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int i = 1; i <= s; s -= i, i *= 2) {
            int vv = i * v, ww = i * w;
            for (int i = V; i >= vv; i--) {
                f[i] = max(f[i], f[i - vv] + ww);
            }
        }
        if (s) {
            int vv = s * v, ww = s * w;
            for (int i = V; i >= vv; i--) {
                f[i] = max(f[i], f[i - vv] + ww);
            }
        }

    }


    cout << f[V] << endl;

    return 0;
}