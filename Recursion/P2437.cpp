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

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
vector<int> add(const vector<int>& A, const vector<int>& B) {
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
LL m, n;
vector<int> arr[1005];
int main() {
  cin >> m >> n;
  arr[m] = arr[m + 1] = {1};
  for (int i = m + 2; i <= n; i++) {
    arr[i] = add(arr[i - 1], arr[i - 2]);
  }
  for (int i = arr[n].size() - 1; i >= 0; i--) cout << arr[n][i];
  cout << endl;

  return 0;
}