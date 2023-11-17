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
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << 12;

LL f[N][M];
bool st[M];
vector<int> arr[M];

int n, m;

bool check(int k, int n) {
    int cnt = 0;
    while (n--) {
        if (k & 1) {
            if (cnt % 2) return false;
            cnt = 0;
        }
        else cnt++;
        k >>= 1;
    }

    return cnt % 2 == 0;
}

int main() {

    while (cin >> n >> m, (n && m)) {
        memset(f, 0, sizeof f);
        memset(st, 0, sizeof st);

        f[0][0] = 1;
        for (int i = 0; i < 1 << n; i++) {
            st[i] = check(i, n);
        }

        for (int j = 0; j < 1 << n; j++) {
            arr[j].clear();
            for (int k = 0; k < 1 << n; k++) {
                if ((j & k) == 0 && st[j | k]) {
                    arr[j].push_back(k);
                }
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < 1 << n; j++) {
                for (auto k: arr[j]) {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
        cout << f[m][0] << endl;
    }

    return 0;
}
