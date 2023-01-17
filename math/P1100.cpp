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

#define MAX_N
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;


int main() {
  unsigned int x;
  cin >> x;
  unsigned int t = x & ((1ul << 16) - 1);
  t <<= 16;
  t += (x >> 16);
  cout << t << endl;
  return 0;
}
