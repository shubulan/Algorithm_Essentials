#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 100005;


int main() {
  int n, cnt = 0;
  vector<vector<int>> vec;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    vec.push_back({b, a});
  }
  sort(vec.begin(), vec.end());
  for (int i = 0, j = 0; i < vec.size();) {
    cnt++;
    while (j < vec.size() && vec[j][1] <= vec[i][0]) j++;
    i = j;
  }
  cout << cnt << endl;


  return 0;
}