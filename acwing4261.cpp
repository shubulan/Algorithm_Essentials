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
int n;

vector<int> add(const vector<int>& A, const vector<int> &B) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size() || i < B.size(); i++) {
    if (i < A.size()) t += A[i];
    if (i < B.size()) t += B[i];
    C.push_back(t % 10);
    t /= 10;
  }
  if (t) C.push_back(t);
  return C;
}

int main() {
  string s;
  cin >> n >> s;
  vector<int> larr(n), rarr(n);
  int lh = -1, lg = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
        larr[i] = lg;
        lg = i;
    } else {
        larr[i] = lh;
        lh = i;
    }
  }

  lg = lh = n;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'G') {
        rarr[i] = lg;
        lg = i;
    } else {
        rarr[i] = lh;
        lh = i;
    }
  }

  vector<int> res = {0};
  for (int i = 0; i < n; i++) {
      LL l = i - larr[i], r = rarr[i] - i;
      LL t = (l * r) ;
      if (r >= 2) t -= 2;
      else t -= 1;
      if (l >= 2) t -= 1;
      vector<int> x;
      while (t) {
          x.push_back(t % 10);
          t /= 10;
      }
      res = add(res, x);
  }
  for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
  cout << endl;

  return 0;
}