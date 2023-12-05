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

bool is_prime(int a) {
    for (int i = 2;i <= a / i; i++) {
        if (a % i == 0) return false;
    }
    return true;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    cout << (is_prime(a) ? "Yes" : "No") << endl;
  }

  return 0;
}