#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_N 1000
typedef long long LL;
int n, x;
int los[MAX_N + 5], win[MAX_N + 5], md[MAX_N + 5];
LL mem[MAX_N + 5][MAX_N + 5];

LL dfs(int i, int x) {
    if (i == n) return 0;
    if (mem[i][x] != -1) return mem[i][x];

    LL res = dfs(i + 1, x) + los[i];
    if (x >= md[i]) {
        res = max(res, dfs(i + 1, x - md[i]) + win[i]);
    }
    return mem[i][x] = res;
}

int main() {
    memset(mem, -1, sizeof mem);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> los[i] >> win[i] >> md[i];
    }

    cout << 5 * dfs(0, x) << endl;
    return 0;
}