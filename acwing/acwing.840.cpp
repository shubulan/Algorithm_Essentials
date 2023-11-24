/**
拉链法
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100003;
int h[N], e[N], nx[N], idx;

void insert(int x) {
  int hs = (x % N + N) % N;
  e[idx] = x;
  nx[idx] = h[hs];
  h[hs] = idx++;
  return;
}

bool query(int x) {
  int hs = (x % N + N) % N;
  for (int i = h[hs]; ~i; i = nx[i]) {
    if (e[i] == x) return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  memset(h, -1, sizeof(h));
  for (int i = 0; i < n; i++) {
    char c;
    int x;
    cin >> c >> x;
    if (c == 'I') insert(x);
    else if (c == 'Q') {
      if (query(x)) puts("Yes");
      else puts("No");
    }
  }

  return 0;
}