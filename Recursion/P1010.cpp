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

#define MAX_N 5000
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL arr[MAX_N + 5];

void dfs(int n, string& out) {
    if (n == 0) {
        out.push_back('0');
        return;
    }
    int flag = 0;
    for (int i = 31; i >= 0; i--) {
        if (flag && out.back() != '+') out.push_back('+');
        if (n & (1 << i)) {
            flag = 1;
            out.push_back('2');
            if (i == 1) continue;
            out.push_back('(');
            dfs(i, out);
            out.push_back(')');
        }
    }
    while (out.back() == '+') out.pop_back();
    
}

int main() {
  int n;
  cin >> n;
  string s;
  dfs(n, s);
  cout << s << endl;
  return 0;
}
