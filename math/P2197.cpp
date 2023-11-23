#include <algorithm>
#include <climits>
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
int t, n, a, res;

/**
 * 先理解公平组合游戏：两个人交互行动，两个人的操作规则完全一致，并且总会结束。
 * 再理解必败态：当前需要行动，无论怎么操作，都会输的状态。
 *     (注意再公平组合游戏中，两人的操作完全一致，所以必败态只跟当前操作的人有关)
 * 证明：
 * 易证：当所有数为0时，是必败态。
 * 证明：f(a) = a1 ^ a2 ^ a3 ^ a4 ^ a5 ... ^ an = 0 时是必败态
 * 1. 证明 f(a) == x != 0 时，可以通过拿走一部分数使f(a') == 0;
 * 2. 证明 f(a) == 0 时，无论拿走多少数，f(a') != 0;
 * 这样，初始f(a) != 0, 我能保证永远给对手留下f(a) = 0的状态。
 * 由于数组a的总和在不断减小，最终一定会给到对手必败态，我一定会赢。
 * 反之，我一定会输
 */
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    res = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a);
      res ^= a;
    }
    printf("%s\n", res == 0 ? "No" : "Yes");
  }

  return 0;
}