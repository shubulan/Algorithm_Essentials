
```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;

vector<int> G[N];
int n;
int par[N], s[N];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}
int merge(int x, int y) {
    x = find(x), y = find(y);
    par[x] = y;
    if (x != y)
        s[y] += s[x];
    return s[y];
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, a;
        cin >> t;
        while (t--) {
            cin >> a;
            G[i].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++) par[i] = i, s[i] = 1;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < G[i].size(); j++) {
            int u = G[i][j];
            if (u < i) continue;
            int mx = merge(i, u);
            if (mx > n / 2) {
                cout << i << endl;
                exit(0);
            }
        }
    }
    
    return 0;
}
```