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

string s;
int n, res;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] != 'x') continue;
    int j = i;
    while (j < n && s[j] == 'x') j++;
    if (j - i >= 3) res += j - i - 2;
    i = j;
  }
  cout << res << endl;
  return 0;
}