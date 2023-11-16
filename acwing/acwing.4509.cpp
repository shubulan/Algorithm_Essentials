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
typedef pair<int, int> PII;

const int N = 1005;
int n;
int a[N + 5];


int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int s = 0;
  for (int i = 0; i < n; i++) s += a[i];
  double m = double(s) / n;
  double s2 = 0;
  for (int i = 0; i < n; i++)  s2 += (double(a[i]) - m) * (double(a[i]) - m);
  double d = s2 / n;
  d = sqrt(d);
  for (int i = 0; i < n; i++) {
      printf("%lf\n", (double(a[i]) - m) / d);
  }
    


  return 0;
}
