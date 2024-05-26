---
head:
  - - link
    - rel: stylesheet
      href: https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.5.1/katex.min.css
---
$f(A)$ = `数组 A 打家劫舍问题`

* $f00(A)$ 不选 A 的第一个数和最后一个数的情况下，计算打家劫舍
* $f01(A)$ 不选 A 的第一个数，最后一个数随便，计算打家劫舍
* $f10(A)$ 不选 A 的最后一个数，第一个数随便，计算打家劫舍
* $f11(A)$ 数组 A 打家劫舍问题

* $f11(A) = max(f10(l) + f11(r), f11(l) + f01(r))$
* $f01(A) = max(f00(l) + f11(r), f01(l) + f01(r))$
* $f10(A) = max(f11(l) + f00(r), f10(l) + f10(r))$
* $f00(A) = max(f01(l) + f00(r), f00(l) + f10(r))$


```c++
class Solution {
public:
    vector<array<int, 4>> dat; // f00, f10, f01, f11;
    void build_tree(int root, int l, int r, vector<int>& arr) {
        if (l == r) {
            dat[root][3] = max(arr[l], 0);
            return;
        }
        int mid = (l + r) / 2;
        build_tree(root * 2, l, mid, arr);
        build_tree(root * 2 + 1, mid + 1, r, arr);

        maintain(root);
        return;
    }

    void init(int n, vector<int>& arr) {
        int bit_len = 0, n_ = n;
        while (n_) { // bit_len = 32 - __builtin_clz(n)
            n_ /= 2;
            bit_len++;
        }
        dat.resize(2 << bit_len);
        build_tree(1, 0, n - 1, arr);
    }

    void modify(int root, int l, int r, int idx, int val) {
        if (l == r) {
            dat[root][3] = max(val, 0);
            return;
        }
        
        int mid = (l + r) / 2;
        if (idx <= mid) modify(root * 2, l, mid, idx, val);
        else modify(root * 2 + 1, mid + 1, r, idx, val);

        maintain(root);
    }

    void maintain(int root) {
        auto& a = dat[root * 2], b = dat[root * 2 + 1];
        dat[root] = {
            max(a[0] + b[2], a[1] + b[0]),
            max(a[0] + b[3], a[1] + b[1]),
            max(a[2] + b[2], a[3] + b[0]),
            max(a[2] + b[3], a[3] + b[1]),
        };
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        init(n, nums);
        cout << dat[1][3] << endl;
        int res = 0, mod = 1e9+7;
        for (auto &q : queries) {
            int i = q[0], x = q[1];
            modify(1, 0, n - 1, i, x);
            cout << dat[1][3] << endl;
            res = (res + dat[1][3]) % mod;
        }
        return res;
    }
};
```