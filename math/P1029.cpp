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

int a, b, res;
int gcd(int a, int b) {
  if (b) return gcd(b, a % b);
  return a;
}
int main() {
  cin >> a >> b;
  int t = a * b;
  for (int i = a; i <= b; i++) {
    if (t % i) continue;
    int x = t / i;
    if (gcd(i, x) == a) {
      res++;
    }
  }
  cout << res << endl;
  return 0;
}