#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long LL;

using namespace std;
const int N = 100005;
int arr[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  LL res = 0;
  for (int i = 0; i < n; i++) res += arr[i] * (n - i - 1);
  cout << res << endl;

  return 0;
}