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
#include <cassert>

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