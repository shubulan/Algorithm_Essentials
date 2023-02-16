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
int arr[10], res;
int main() {
  cin >> s;
  int n = s.size();
  string a = "a";
  res = 1;
  while (a != s) {
    res++;
    if (a.back() != 'z') {
      a.back()++;
    } else {
      int n = a.size();
      int i = a.size() - 1;
      char b = 'z';
      for (; i >= 0; i--, b--) {
        if (a[i] != b) break;
      }
      if (i < 0) {
        a.push_back('a');
        char t = 'a';
        for (int i = 0; i <= n; i++) a[i] = (t + i);
      } else {
        a[i]++;
        for (int j = 1, k = i + 1; k < n; k++, j++) {
          a[k] = a[i] + j;
        }
      }
    }
    // cout << res << " " << a << endl;
  }
  cout << res << endl;
  return 0;
}
