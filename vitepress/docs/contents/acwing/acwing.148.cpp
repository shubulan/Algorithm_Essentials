#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 10005;

int arr[N];

int main() {
  int n, a, cnt = 0;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> que;
  for (int i = 0; i < n; i++) {
    cin >> a;
    que.push(a);
  }
  while (que.size() != 1) {
    int a = que.top();
    que.pop();
    int b = que.top();
    que.pop();
    cnt += a + b;
    que.push(a + b);
  }

  // sort(arr, arr + n, greater<int>());
  // for (int i = n - 2; i >= 0; i--) {
  //   arr[i] += arr[i + 1];
  //   cnt += arr[i];
  //   for (int )
  //   sort(arr, arr + i + 1, greater<int>());
  // }
  cout << cnt << endl;


  return 0;
}