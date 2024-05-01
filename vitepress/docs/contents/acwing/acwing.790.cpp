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
typedef pair<int, int> PII;

int main() {
  double x;
  scanf("%lf\n", &x);
  double l = -10000.0, r = 10000.0;
  while (r - l > 1e-7) {
    double mid = (l + r) / 2;
    if ((mid * mid * mid) < x)
      l = mid;
    else
      r = mid;
  }
  printf("%.6f\n", l);

  return 0;
}