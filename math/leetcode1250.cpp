class Solution {
 public:
  bool isGoodArray(vector<int>& nums) {
    for (int i = 0, a = 0; i < nums.size(); i++) {
      a = gcd(a, nums[i]);
      if (a == 1) return true;
    }
    return false;
  }
};

/**
 * 证明：
 * 1. 先证明对于a,b两数，如果ax + by = 1有解，必有gcd(a, b) == 1
 * 如果ax + by = 1，并且gcd(a, b) == k且，k ！= 1 ，
 * 那么 等式两边必能同除以k以约分。但是右边是1,不能约分。所以矛盾。
 * 同理可证明如果 a1*x1 + a2*x2 + a3*x3 ... an*xn= 1，则必有gcd(a1...an) == 1。
 * 2. 证明 gcd(a, b) == 1， ax + by = 1必有解。
 *    显而易见
 * 3. 证明 gcd(a1, a2...an) == 1, a1*x1 + a2*x2 + a3*x3 ... an*xn= 1必有解。
 *    该问题是「裴蜀定理」重要推论
 * 4. 证明 对于数组a1 ....an，
 *  存在gcd(subset(a)) = 1  等价于 gcd(a1,a2...an) = 1
 *  因为数组中一部分的最大公约数为1,那么显然整体的最大公约数是1.
 *  如果整体的最大公约数是1,那么至少整体的最大公约数是1。证必。
 *
 */