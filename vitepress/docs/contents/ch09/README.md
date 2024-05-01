# ch08 搜索与图论 II

## 图论 II

### 最小生成树

### 二分图

* 二分图判定


* 二分图匹配
要点：
* 在知道是二分图的前提下，问最多有多少个匹配对数
* 图随便建，要点在于如何将节点分为两部分。
* 枚举其中一部分，在另一部分中找配对
* [HJ28 素数伴侣](https://www.nowcoder.com/practice/b9eae162e02f4f928eac37d7699b352e?tpId=37&tqId=21251&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=5&judgeStatus=undefined&tags=&title=)
* 素数伴侣必然一个奇数，一个偶数。我们可以通过奇偶性将节点分为两部分

```
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
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
 
int h[105], e[10005], nx[10005], idx;
int nums[105], ph[105];
bool st[105];
int n;
void add(int a, int b) {
    e[idx] = b;
    nx[idx] = h[a];
    h[a] = idx++;
}
 
bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
 
bool find(int x) {
    for (int i = h[x]; ~i; i = nx[i]) {
        int j = e[i];
        if (st[j]) continue;
         
        // st[j] = true;
        if (ph[j] == 0) {
            ph[j] = x;
            return true;
        }
 
        st[j] = true;
 
        if (find(ph[j])) {
            ph[j] = x;
            st[j] = false;
            return true;
        }
    }
    return false;
}
 
int hungary() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (nums[i] % 2) continue;
        memset(st, 0, sizeof st);
        if (find(i)) cnt++;
    }
    return cnt;
}
 
int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        for (int j = 1; j < i; j++) {
            if (is_prime(nums[i] + nums[j])) {
                add(i, j);
                add(j, i);
            }
        }
    }
 
    cout << hungary() << endl;
    return 0;
}
```
