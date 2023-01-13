#include <iostream>
using namespace std;

int exgcd(int a, int b, int *x, int *y) {
    if (!b) {
        *x = 1, *y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    *y -= a / b * (*x);
    return d;
}

int main() {
    int x, y;
    int a = 3, b = 5;
    while (cin >> a >> b) {
      int d = exgcd(a, b, &x, &y);
      printf("%dx%d + %dx%d = %d\n", x, a, y, b, d);
    }

    return 0;
}

