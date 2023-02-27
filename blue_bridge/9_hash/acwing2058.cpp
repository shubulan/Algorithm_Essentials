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

string s1, s2;
unordered_map<int, int> mmap;
int to_dec(string &s, int base) {
  int n = s.size(), res = 0;
  for (int i = n - 1, r = 1; i >= 0; i--, r *= base) {
    res += (s[i] - '0') * r;
  }
  return res;
}
int main() {
  cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); i++) {
    char c = s1[i];
    for (int j = 0; j < 2; j++) {
      if (s1[i] == '0' + j) continue;
      s1[i] = '0' + j;
      int x = to_dec(s1, 2);
      s1[i] = c;
      mmap[x]++;
    }
    
  }
  for (int i = 0; i < s2.size(); i++) {
    char c = s2[i];
    for (int j = 0; j < 3; j++) {
      if (s2[i] == j + '0') continue;
      s2[i] = j + '0';
      int x = to_dec(s2, 3);
      if (mmap.count(x)) {
        printf("%d\n", x);
        return 0;
      }
      s2[i] = c;
    }
    
  }

  return 0;
}