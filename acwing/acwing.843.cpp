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

const int N = 10;
int n, idx;
char b[N][N];

void dfs() {
    if (idx == n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) cout << b[i][j];
            cout << endl;
        }
        cout << endl;
        return;
    }
    idx++;
    for (int i = 1; i <= n; i++) {
        int flag = 0;
        for (int j = 1; j < idx; j++) if (b[j][i] == 'Q') flag = 1;
        for (int j = i - 1, k = idx - 1; j > 0 && k > 0; j--, k--) if (b[k][j] == 'Q') flag = 1;
        for (int j = i + 1, k = idx - 1; j <= n && k > 0; j++, k--) if (b[k][j] == 'Q') flag = 1;
        
        if (flag) continue;
        
        b[idx][i] = 'Q';
        dfs();
        b[idx][i] = '.';
    }
    idx--;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) b[i][j] = '.';
  dfs();

  return 0;
}