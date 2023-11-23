/*
1. 集合计数问题：想像求组合数
C(m, n):从n个数中选m个等于 C(m, n) = C(m, n - 1) + C(m - 1, n - 1)
    1. 先从n-1个数选m个：C(m, n - 1)
    2. 再从n-1个数中选 m - 1个，与n配成m个数
2. 本题目中，要求集合内数的乘积，不可以有平方数约数，
    问题规约成集合内所有数的所有质因数不可以重复。为什么只考虑质数？
        如果是平方数16,那么其实考虑4的时候就已经考虑过了,它是质数2的平方。
        所有非质数的平方，一定可以分解为多个质数的平方相乘，所以没有必要考虑非质数
    由于数字ai <= 30，因此可能出现的质数为：
    int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; 共10个。
    用一个10位的二进制数来表示当前集合是否存在某一个质数。
    对于一个数ai分解质因数。
        如果某个质数的数量 >=
2，则意味着，它不可以放入任何一个集合中，因为本身就不满足。 如果所有质数的数量
<= 1，则能构造一个值 y,其二进制假设为 (1, 0, 1, 0,  0,  0,  0,  0,  0,  0)
表示它有两个质因数 : 2, 5 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
    如果一个集合的存在的质因数的表示为(1, 0, 0, 0, 0...),
则表示这个数不可以加入该集合中形成新集合。
    因为集合中已经有一个质因数2了，不可以在多一个2.
    如果一个集合的存在的质因数的表示为(0, 1, 0, 1, 0, 0, ...)，
则表示这个数可以加入该集合中形成新集合。
    新集合的数量为源集合的数量，新集合的表示为
    (1, 0, 1, 0, 0000) & (0, 1, 0, 1, 0000) = (1, 1, 1, 1, 0000)
3. 分析完毕，定义状态
f(i)(y) 表示为前i个数中，质数状态为y的集合的数量。
假设i的分解质因数后不满足条件，直接continue
假设i的分解质因数后的状态为 z
f(i)(y | z) = f(i - 1)(y | z) + f(i - 1)(y) (y & z != 1)
f(i)(z) = f(i)(z) + 1 (自己单成一个集合)

代码如下
*/

class Solution {
 public:
  int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  int pc = 10, mod = 1e9 + 7;
  int squareFreeSubsets(vector<int>& nums) {
    unordered_map<int, int> mmap;
    for (auto x : nums) {
      int y = 0, flag = 0;
      for (int i = 0; i < pc; i++) {
        int p = primes[i], ct = 0;
        while (x % p == 0) x /= p, ct++;
        if (ct >= 2) {
          flag = 1;
          break;
        }
        y |= (ct << i);
      }
      if (flag) continue;

      for (int i = (1 << pc) - 1; i >= 0; i--) {
        if (i & y) continue;
        mmap[i | y] += mmap[i];
        mmap[i | y] %= mod;
      }
      mmap[y]++;
    }
    int res = 0;
    for (auto& x : mmap) {
      res += x.second;
      res %= mod;
    }
    return res;
  }
};