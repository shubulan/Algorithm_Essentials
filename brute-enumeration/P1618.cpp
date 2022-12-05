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

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
  int flg = 0;
  do {
    int ta = 0;
    for (int i = 0; i < 3; i++) {
      ta = ta * 10 + arr[i];
    }
    int tb = 0;
    for (int i = 3; i < 6; i++) {
      tb = tb * 10 + arr[i];
    }
    int tc = 0;
    for (int i = 6; i < 9; i++) {
      tc = tc * 10 + arr[i];
    }
    if (ta * b == tb * a && tc * b == tb * c) {
      flg = 1;
      printf("%d %d %d\n", ta, tb, tc);
    }

  } while (next_permutation(arr.begin(), arr.end()));
  if (!flg) {
    printf("No!!!\n");
  }

  return 0;
}