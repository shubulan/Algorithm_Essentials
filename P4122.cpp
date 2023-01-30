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
/**
 * 离散化入门好题
*/
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
int X[10], Y[10];
PII arr[10];
bool in_rect(int x1, int y1, int x2, int y2) {
  if (x1 >= arr[4].x && y1 >= arr[4].y && x2 <= arr[5].x && y2 <= arr[5].y) return false;
  if (x1 >= arr[0].x && y1 >= arr[0].y && x2 <= arr[1].x && y2 <= arr[1].y) return true;
  if (x1 >= arr[2].x && y1 >= arr[2].y && x2 <= arr[3].x && y2 <= arr[3].y) return true;
  return false;
}
int main() {
  for (int i = 0; i < 6; i++) {
    cin >> X[i] >> Y[i];
    arr[i].x = X[i];
    arr[i].y = Y[i];
  }
  sort(X, X + 6);
  sort(Y, Y + 6);
  int res = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (in_rect(X[i], Y[j], X[i + 1], Y[j + 1])) res += (Y[j + 1] - Y[j]) * (X[i + 1] - X[i]);
    }
  }
  cout << res << endl;


  return 0;
}
