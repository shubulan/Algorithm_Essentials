```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 20005;

int a, b;

LL count(int x, int d) {
    vector<int> nums;
    int xx = x;
    while (x) {
        nums.push_back(x % 10);
        x /= 10;
    }
    LL res = 0, h = xx / 10, t = 0, p = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (h) { // 0 ~ abc - 1
            res += h * p;
            if (d == 0) res -= p;
        }
        // h == abc
        if (d == 0 && h == 0) continue;
        if (nums[i] == d) {
            res += t + 1;
        } else if (d < nums[i]) {
            res += p;
        }

        t += nums[i] * p;
        h /= 10;
        p *= 10;
    }

    return res;
}

int main() {

    while (cin >> a >> b, (a && b)) {
        if (a > b) swap(a, b);
        for (int i = 0; i < 10; i++) {
            cout << count(b, i) - count(a - 1, i) << " ";
        }
        cout << endl;
    }

    return 0;
}
```