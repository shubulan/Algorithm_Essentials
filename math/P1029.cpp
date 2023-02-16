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