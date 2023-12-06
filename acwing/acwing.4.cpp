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
typedef pair<int, int> PII;
const int N = 105;
int f[N];
int main() {
    int n, V;
    cin >> n >> V;
    while (n--) {
        int v, w, s;
        cin >> v >> w >> s;
        while (s--) {
            for (int i = V; i >= v; i--) {
                f[i] = max(f[i], f[i - v] + w);
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= V; i++) res = max(res, f[i]);
    cout << res << endl;

    return 0;
}
