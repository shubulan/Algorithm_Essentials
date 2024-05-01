#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/**
 * 证明题：全异或为零必败，不为0必胜。
 * 如果异或不为0.我可以找到一种方法，拿出一部分数后，让剩下的数为0.
 * 如果异或为0，那么不管我怎么拿，结果的异或值都不为0
 * 
 * 根据以上两点，可以从全是0的必败态，数学归纳出，所有异或为0的状态都是必败态。
 * 而不为0的状态，可以通过操作将必败态留给对方，也就是自己是必胜态
 */

int main() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    res ^= a;
  }
  if (res) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}