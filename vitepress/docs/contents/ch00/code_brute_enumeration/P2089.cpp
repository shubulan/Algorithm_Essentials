#include <algorithm>
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
LL res, n;
vector<int> tmp;
vector<vector<int>> ress;
void judge() {
  LL x = 0;
  for (int i = 0; i < tmp.size(); i++) {
    x += tmp[i];
  }
  if (x == n) {
    res++;
    ress.push_back(tmp);
  }
}
void dfs(int i) {
  if (i == 11) {
    judge();
    return;
  }
  for (int k = 1; k <= 3; k++) {
    tmp.push_back(k);
    dfs(i + 1);
    tmp.pop_back();
  }
}

int main() {
  cin >> n;
  dfs(1);
  cout << res << endl;
  for (int i = 0; i < ress.size(); i++) {
    for (int j = 0; j < ress[i].size(); j++) {
      cout << ress[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}