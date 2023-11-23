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
#define MAX_N 30

LL arr[MAX_N + 5];
int n;
int main() {
  cin >> n;
  arr[0] = arr[1] = 1;
  for (int i = 2; i <= n; i++) {
    LL res = 0;
    for (int j = 0; j < i; j++) res += arr[j] * arr[i - j - 1];
    arr[i] = res;
  }
  cout << arr[n] << endl;
  return 0;
}