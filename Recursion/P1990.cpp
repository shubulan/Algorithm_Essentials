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
const int N = 1000005;
int arr[N], G[N];
int n;

int main() {
  cin >> n;
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 2;
  for (int i = 3; i <= n; i++) {
    G[i] = arr[i - 3] + G[i - 1];
    G[i] %= 10000;
    arr[i] = arr[i - 1] + arr[i - 2] + 2 * G[i];
    arr[i] %= 10000;
  }
  cout << arr[n] << endl;
  return 0;
}