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
typedef pair<int, int> PII;

#define MAX_N 1000
int arr[MAX_N + 5];
int dfs(int n) {
  if (arr[n] != 0) return arr[n];
  int res = 1;
  for (int i = 1; i <= n / 2; i++) {
    res += dfs(i);
  }
  return arr[n] = res;
}

int main() {
  arr[1] = 1;
  int n;
  cin >> n;
  // cout << dfs(n) << endl;
  for (int i = 2; i <= n; i++) {
    int res = 1;
    for (int j = 1; j <= i / 2; j++) {
      res += arr[j];
    }
    arr[i] = res;
  }
  cout << arr[n] << endl;
  return 0;
}