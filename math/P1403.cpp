#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL n, res;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    res += n / i;
  }
  cout << res << endl;
  return 0;
}