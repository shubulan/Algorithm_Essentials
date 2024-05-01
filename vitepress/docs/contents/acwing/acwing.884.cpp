#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 105;

int arr[N][N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n + 1; j++) cin >> arr[i][j];
  }
  for (int i = 0; i < n; i++) {  // eliminate top to down
    int idx = i;
    for (int j = i + 1; j < n; j++) {  // find 1
      if (arr[j][i] == 1) {
        idx = j;
        break;
      }
    }

    if (arr[idx][i] == 0) continue;

    if (idx != i) {  // swap line
      for (int j = i; j < n + 1; j++) {
        swap(arr[idx][j], arr[i][j]);
      }
    }

    for (int j = i + 1; j < n; j++) {
      if (arr[j][i] == 0) continue;
      for (int k = i; k < n + 1; k++) {
        arr[j][k] ^= arr[i][k];
      }
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    // cout << "==============" << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n + 1; j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }
    // cout << "============" << endl;
    if (arr[i][i] == 0 && arr[i][n] == 1) {
      printf("No solution\n");
      return 0;
      return -1;
    }

    if (arr[i][i] == 0 && arr[i][n] == 0) {
      printf("%d\n", i);
      printf("Infinite group solutions\n");
      return 0;
      return -2;
    }

    for (int k = i - 1; k >= 0; k--) {
      arr[k][n] ^= arr[i][n] * arr[k][i];
      arr[k][i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i][n]);
  }

  return 0;
}
