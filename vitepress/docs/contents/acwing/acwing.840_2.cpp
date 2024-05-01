/**
开放寻址法
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200003;
int h[N], null = 0x3f3f3f3f;

int find(int x) {
  int hs = (x % N + N) % N;
  while (h[hs] != null && h[hs] != x) hs++;
  return hs;
}


int main() {
  int n;
  cin >> n;
  memset(h, 0x3f, sizeof(h));
  for (int i = 0; i < n; i++) {
    char c;
    int x;
    cin >> c >> x;
    int idx = find(x);
    if (c == 'I') h[idx] = x;
    else if (c == 'Q') {
      if (h[idx] != null) puts("Yes");
      else puts("No");
    }
  }

  return 0;
}