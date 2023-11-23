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
int n;
vector<int> tmp;
vector<int> visited(11);

void dfs(int c) {
  if (c == n) {
    for (int i = 0; i < n; i++) {
      cout << "    " << tmp[i];
    }
    cout << endl;
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;

    visited[i] = 1;
    tmp.push_back(i);
    dfs(c + 1);
    visited[i] = 0;
    tmp.pop_back();
  }
  return;
}

int main() {
  cin >> n;

  // for (int i = 1; i <= n; i++) {
  //   tmp.push_back(i);
  // }
  // do {
  //   for (int i = 0; i < n; i++) {
  //     cout << "    " << tmp[i];
  //   }
  //   cout << endl;
  // } while(next_permutation(tmp.begin(), tmp.end()));
  dfs(0);

  return 0;
}