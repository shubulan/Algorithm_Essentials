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

#define MAX_N
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int n;
double suma, sumb;
int arra[15], arrb[15];

double get(int v, int l) {
  double x = 0.0;
  if (v < 60)
    x = 0.0;
  else if (v <= 63)
    x = 1.0;
  else if (v <= 67)
    x = 1.5;
  else if (v <= 71)
    x = 2.0;
  else if (v <= 74)
    x = 2.3;
  else if (v <= 77)
    x = 2.7;
  else if (v <= 81)
    x = 3.0;
  else if (v <= 84)
    x = 3.3;
  else if (v <= 89)
    x = 3.7;
  else
    x = 4.0;
  return x * l;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arra[i];
  for (int i = 0; i < n; i++) cin >> arrb[i];

  for (int i = 0; i < n; i++) {
    double x = get(arrb[i], arra[i]);
    suma += x;
    sumb += arra[i];
  }
  printf("%.2f\n", suma / sumb);

  return 0;
}
