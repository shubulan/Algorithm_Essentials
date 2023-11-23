#include <algorithm>
#include <cassert>
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

const int N = 100005;

int get_bits(int a) {
  int cnt = 0;
  // while (a) {
  //     if (a & 1) cnt++;
  //     a >>= 1;
  // }
  while (a) {
    cnt++;
    a -= a & (-a);
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    cout << get_bits(a) << " ";
  }
  cout << endl;

  return 0;
}