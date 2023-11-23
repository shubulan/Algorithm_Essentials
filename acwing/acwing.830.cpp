#include <algorithm>
#include <cassert>
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

const int N = 100005;

int arr[N];
int main() {
  stack<int> st;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    if (st.empty())
      cout << -1 << " ";
    else
      cout << arr[st.top()] << " ";
    st.push(i);
  }
  cout << endl;

  return 0;
}