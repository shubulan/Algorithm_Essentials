#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 105;

double arr[N][N];

#define feq(a, b) (fabs(a - b) < 1e-6)
#define fgt(a, b) (fabs(a) - fabs(b) > 0)

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n + 1; j++) cin >> arr[i][j];
  }
  for (int i = 0; i < n; i++) {  // eliminate top to down
    int idx = i;
    for (int j = i + 1; j < n; j++) {  // find max line
      if (fgt(arr[j][i], arr[idx][i])) {
        idx = j;
      }
    }

    if (idx != i) {  // swap line
      for (int j = i; j < n + 1; j++) {
        swap(arr[idx][j], arr[i][j]);
      }
    }
    if (feq(arr[i][i], 0)) continue;

    double b = arr[i][i];
    for (int j = i; j < n + 1; j++) {
      arr[i][j] /= b;
    }

    for (int j = i + 1; j < n; j++) {
      double b = arr[j][i];
      for (int k = i; k < n + 1; k++) {
        arr[j][k] -= b * arr[i][k];
      }
    }
  }
  // for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < n + 1; j++)
  //         cout << arr[i][j] << " ";
  //     cout << endl;
  // }

  for (int i = n - 1; i >= 0; i--) {
    if (feq(arr[i][i], 0) && !feq(arr[i][n], 0)) {
      printf("No solution\n");
      return 0;
      return -1;
    }

    if (feq(arr[i][i], 0)) continue;

    for (int k = i + 1; k < n; k++) {
      if (!feq(arr[i][k], 0)) {
        printf("Infinite group solutions\n");
        return 0;
        return -2;
      }
    }

    for (int k = i - 1; k >= 0; k--) {
      arr[k][n] -= arr[i][n] * arr[k][i];
      arr[k][i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%.2f\n", arr[i][n]);
  }

  return 0;
}
