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

int main() {
  string s;
  cin >> s;
  int n;
  n = s[1] - '0';
  int a = 1189, b = 841;
  for (int i = 0; i < n; i++) {
      a /= 2;
      swap(a, b);
  }
  cout << a << endl;
  cout << b << endl;

  return 0;
}
