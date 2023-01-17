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
const int N = 2005;
LL a[2005][2005];

int main() {
  for (int i = 0; i < 2000; i++) {
    for (int j = 0; j <= i; j++) {
      if (!j) a[i][j] = 1;
      else a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
      if (i <= 30) cout << a[i][j] << " ";
    }
    if (i <= 30) cout << endl;
  }


  return 0;
}