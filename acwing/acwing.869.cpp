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

void dividing(int x) {
  vector<int> res;
  for (int i = 1; i <= x / i; i++) {
    if (x % i == 0) {
        res.push_back(i);
        if (i != x / i) res.push_back(x / i);
    }
  }
  sort(res.begin(), res.end());
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    dividing(x);
  }
  return 0;
}