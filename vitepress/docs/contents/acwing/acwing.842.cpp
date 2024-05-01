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



int path[10], idx, n;;
int st[10];

void dfs(int x) {
    st[x] = 1;
    path[++idx] = x;
    if (idx == n) {
        for (int i = 1; i <= n; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        st[x] = 0;
        idx--;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (st[i]) continue;
        dfs(i);
    }
    st[x] = 0;
    idx--;
}

void dfs2() {
    if (idx == n) {
        for (int i = 1; i <= n; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (st[i]) continue;
        st[i] = 1;
        path[++idx] = i;
        dfs2();
        st[i] = 0;
        --idx;
    }
}

int main() {
  cin >> n;
/**
 * 方法一： dfs(i) 表示我选了i之后的所有路径
*/
//   for (int i = 1; i <= n; i++) { // dfs(i) 表示我选了i之后的所有路径
//     dfs(i);
//   }

/**
 * 方法二： dfs2() 基于现在的状态，把现在的所有选择试一遍。
*/
//   dfs2(); 
// 方法一 方法二 本质上都是递归，只是把某一个状态放在哪里实现的问题。
// 不过看起来方法2 好像更不容易出错。

/**
 * 方法三： next_permutation
*/
  vector<int> res;
  for (int i = 1; i <= n; i++) res.push_back(i);
  do {
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
  } while (next_permutation(res.begin(), res.end()));



  return 0;
}