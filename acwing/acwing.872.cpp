#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
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
typedef pair<int, int> PII;

const int N = 100005;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
  }

  return 0;
}