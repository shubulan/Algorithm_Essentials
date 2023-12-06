#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

const int N = 1000005;
int arr[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int l = 0, r = n - 1;
  int res = 0;
  while (l < r) {
    res += (arr[r] - arr[l]);
    l++, r--;
  }
  cout << res << endl;

  return 0;
}