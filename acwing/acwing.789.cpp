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
const int N = 100005;
int arr[N];

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> arr[i];
  while (q--) {
    int k;
    cin >> k;
    int l = 0, r = n - 1;
    int r1, r2;
    
    l = 0, r = n - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (arr[mid] >= k) r = mid;
        else l = mid + 1;
    }
    
    r1 = l;
    if (arr[r1] != k) r1 = -1; // 如果 r1 不是 k 那么数组中一定不存在 k, 这里完全可以输出结果 -1 -1
    
    
    l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (arr[mid] <= k) l = mid;
        else r = mid - 1;
    }
    r2 = l;
    if (arr[r2] != k) r2 = -1;

    cout << r1 << " " << r2 << endl;
  }
  

  return 0;
}