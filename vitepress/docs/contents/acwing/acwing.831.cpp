#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;
int nxt[N];
int main() {
    int n, m;
    string p, s;
    cin >> n >> p >> m >> s;

    int j  = -1;
    nxt[0] = j;
    for (int i = 1; i < n; i++) {
        while (j != -1 && p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) j++;
        nxt[i] = j;
    }

    for (int i = 0, j = -1; i < m; i++) {
        while (j != -1 && s[i] != p[j + 1]) j = nxt[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n - 1) {
            cout << i - n + 1 << " ";
            j = nxt[j];
        }
    }

    return 0; 
}