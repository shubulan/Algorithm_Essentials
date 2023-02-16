#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>
#include <string>

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