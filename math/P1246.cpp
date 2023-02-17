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
int arr[10], res, f[30][10];
void init() {
  for (int i = 0; i < 30; i++) f[i][1] = 1;
  for (int j = 1; j < 6; j++) {
    int ans = 0;
    for (int i = 25; i > 0; i--) {
      ans += f[i][j];
      f[i - 1][j + 1] = ans;
    }
  }
  
  // for (int i = 0; i < 26; i++) {
  //   for (int j = 0; j <= 6; j++) {
  //     cout << f[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}
int main() {
  cin >> s;
  int n = s.size();
  
  // 模拟法，会tle
  // string a = "a";
  // res = 1;
  // while (a != s) {
  //   res++;
  //   if (a.back() != 'z') {
  //     a.back()++;
  //   } else {
  //     int n = a.size();
  //     int i = a.size() - 1;
  //     char b = 'z';
  //     for (; i >= 0; i--, b--) {
  //       if (a[i] != b) break;
  //     }
  //     if (i < 0) {
  //       a.push_back('a');
  //       char t = 'a';
  //       for (int i = 0; i <= n; i++) a[i] = (t + i);
  //     } else {
  //       a[i]++;
  //       for (int j = 1, k = i + 1; k < n; k++, j++) {
  //         a[k] = a[i] + j;
  //       }
  //     }
  //   }
  //   // cout << res << " " << a << endl;
  // }
  // cout << res << endl;

  // 递推法
  init();
  for (int i = 0, t = 'a'; i < n; i++) {
    if (i && s[i] <= s[i - 1]) {
      res = -1;
      break;
    }
    for (int j = 'a'; j <= 'z'; j++) res += f[j - 'a'][i];
    for (int j = t; j < s[i]; j++) {
      res += f[j - 'a'][n - i];
    }
    t = s[i] + 1;
  }
  cout << res + 1 << endl;
  // adehj -> 21737
  // ade -> 399
  return 0;
}
