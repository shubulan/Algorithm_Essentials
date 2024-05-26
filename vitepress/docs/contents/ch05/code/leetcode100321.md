::: code-group
```c++ [枚举约数]
/*
复杂度 O(nSqrt(U) + m)
*/
class Solution {
public:
    using LL = long long;
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, LL> cnt;
        for (auto x : nums1) {
            if (x % k) continue;
            x /= k;
            for (int i = 1; i <= x / i; i++) {
                if (x % i == 0) {
                    cnt[i]++;
                    if (i != x / i) cnt[x / i] ++;
                }
            }
        }
        LL res = 0;
        for (auto x : nums2) {
            res += cnt[x];
        }
        return res;
    }
};

```
```c++ [枚举倍数]
/*

复杂度 O(n + m + Ulog(m))
*/
class Solution {
public:
    using LL = long long;
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, LL> cnt, cnt2;
        int mx = 0;
        for (auto x : nums1) {
            if (x % k) continue;
            x /= k;
            cnt2[x]++;
            mx = max(x, mx);
        }
        for (auto x : nums2) cnt[x]++;
        LL res = 0;
        for (auto [x, c] : cnt) {
            int s = 0;
            for (int j = x; j <= mx; j += x) {
                s += cnt2.count(j) ? cnt2[j] : 0;
            }
            res += s * c;
        }
        return res;
    }
};

```
:::