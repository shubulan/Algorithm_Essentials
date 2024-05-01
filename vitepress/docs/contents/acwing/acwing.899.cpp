#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int N = 1005, M = 15;

char S[N][M];

int f[M][M];

int n, m;

int edit_distance(char *s1, char *s2) {
  int n = strlen(s1 + 1), m = strlen(s2 + 1);
  for (int i = 0; i <= n; i++) f[i][0] = i;
  for (int i = 0; i <= m; i++) f[0][i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = min({f[i-1][j-1], f[i-1][j], f[i][j-1]}) + 1;
      if (s1[i] == s2[j]) f[i][j] = f[i-1][j-1];
    }
  }
  return f[n][m];

}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> S[i] + 1;
  while (m--) {
    char s[M];
    int L;
    cin >> s + 1 >> L;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (edit_distance(s, S[i]) <= L) cnt++;
    }
    cout << cnt << endl;
  }

  return 0;
}