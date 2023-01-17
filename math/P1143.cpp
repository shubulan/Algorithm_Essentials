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

#define MAX_N
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;


int to_t(char x) {
  if (x >= '0' && x <= '9') return x - '0';
  else return x - 'A' + 10;
}
char to_c(int x) {
  if (x >= 0 && x <= 9) return x + '0';
  else return x - 10 + 'A';
}

string solve(const string&s, int a, int b) {
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    res = res * a + to_t(s[i]);
  }
  string ans;
  while (res) {
    ans.push_back(to_c(res % b));
    res /= b;
  }
  reverse(ans.begin(), ans.end());
  if (ans.empty()) ans.push_back('0');
  return ans;
}
int main() {
  int n, m;
  cin >> n;
  string s;
  cin >> s >> m;
  cout << solve(s, n, m) << endl;
  return 0;
}