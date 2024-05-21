```c++
#define define_mid int mid = (l + r) >> 1;
const int MAX_N = 100000;

struct {
  long long sum, tag;
} tree[MAX_N << 2];
long long arr[MAX_N + 5];

void update(int ind) {
  tree[ind].sum = tree[ind << 1].sum + tree[ind << 1 | 1].sum;
  return;
}
void down(long long ind, long long l, long long r) {
  if (tree[ind].tag % 2) {
    define_mid;
    tree[ind << 1].sum = (mid - l + 1) - tree[ind << 1].sum;
    tree[ind << 1].tag += 1;
    tree[ind << 1 | 1].sum = (r - mid) - tree[ind << 1 | 1].sum;
    tree[ind << 1 | 1].tag += 1;
    tree[ind].tag = 0;
  } else {
    tree[ind].tag = 0;
  }
  return;
}
void build_tree(long long ind, long long l, long long r) {
  if (l == r) {
    tree[ind].sum = arr[l];
    return;
  }
  define_mid;
  build_tree(ind << 1, l, mid);
  build_tree(ind << 1 | 1, mid + 1, r);
  update(ind);
  return;
}
void modify(long long ind, long long l, long long r, long long x, long long y,
            long long val) {
  if (x <= l && r <= y) {
    tree[ind].sum = r - l + 1 - tree[ind].sum;
    tree[ind].tag += 1;
    return;
  }
  down(ind, l, r);
  define_mid;
  if (mid >= x) {
    modify(ind << 1, l, mid, x, y, val);
  }
  if (mid < y) {
    modify(ind << 1 | 1, mid + 1, r, x, y, val);
  }
  update(ind);
  return;
}
long long query(long long ind, long long l, long long r, long long x,
                long long y) {
  if (x <= l && r <= y) {
    return tree[ind].sum;
  }
  down(ind, l, r);
  define_mid;
  long long ans = 0;
  if (mid >= x) {
    ans += query(ind << 1, l, mid, x, y);
  }
  if (mid < y) {
    ans += query(ind << 1 | 1, mid + 1, r, x, y);
  }
  return ans;
}

class Solution {
 public:
  vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2,
                                vector<vector<int>>& queries) {
    int n = nums1.size();
    vector<long long> resv;
    memset(tree, 0, sizeof tree);
    for (int i = 0; i < n; i++) {
      arr[i] = nums1[i];
    }
    long long res = 0;
    for (int i = 0; i < n; i++) res += nums2[i];
    build_tree(1, 0, n - 1);
    for (auto& vec : queries) {
      int op = vec[0], l = vec[1], r = vec[2];
      if (op == 1) {
        modify(1, 0, n - 1, l, r, 1);
      } else if (op == 2) {
        long long x = query(1, 0, n - 1, 0, n - 1);
        res += x * l;
        // cout << x << endl;
      } else {
        resv.push_back(res);
      }
    }
    return resv;
  }
};
```