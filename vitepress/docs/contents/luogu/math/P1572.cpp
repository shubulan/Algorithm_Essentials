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
LL a = 0, b = 1, ca, cb, num, f;
string s;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
void cacl() {
  // printf("%lld %lld %lld %lld\n", a, b, ca, cb);
  a *= cb;
  ca *= b;
  b *= cb;
  if (f)
    a -= ca;
  else
    a += ca;
  int t = gcd(abs(a), b);
  a /= t;
  b /= t;
}
int main() {
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c == '/') {
      ca = num;
      num = 0;
    } else if (c == '+' || c == '-') {
      cb = num;
      num = 0;
      cacl();
      if (c == '+')
        f = 0;  // 计算加法
      else
        f = 1;
    } else {
      num = num * 10 + c - '0';
    }
  }
  cb = num;
  cacl();
  if (b == 1) {
    cout << a << endl;
  } else {
    cout << a << "/" << b << endl;
  }

  return 0;
}