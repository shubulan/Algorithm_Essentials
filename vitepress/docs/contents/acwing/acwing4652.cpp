#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

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
