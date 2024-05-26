
::: code-group
```c++ [纯线段树解]
/*
    线段树中存：区间中最大的空位，左边连续的空位，右边连续的空位
*/
class Solution {
public:
    const int n = 50010;
    vector<int> dat, dl, dr;
    
    void build_tree(int root, int l, int r) {
        if (l + 1 == r) {
            dat[root] = dl[root] = dr[root] = 1;
            return;
        }

        int mid = (l + r) >> 1;
        build_tree(root * 2, l, mid);
        build_tree(root * 2 + 1, mid, r);
        dat[root] = dl[root] = dr[root] = r - l;
        return;
    }

    void init() {
        int bit_len = 32 - __builtin_clz(n);
        dat.resize(2 << bit_len);
        dl.resize(2 << bit_len);
        dr.resize(2 << bit_len);

        build_tree(1, 0, n);
    }
    
    void modify(int root, int l, int r, int idx) {
        if (l + 1 == r) { // 至少一格
            dat[root] = 1;
            if (l == idx) dl[root] = 0;
            else dr[root] = 0;
            return;
        }
        int lc = root * 2, rc = root * 2 + 1;

        int mid = (l + r) >> 1;
        if (idx <= mid) modify(lc, l, mid, idx);
        if (idx >= mid) modify(rc, mid, r, idx);

        dat[root] = max({dat[lc], dat[rc], dr[lc] + dl[rc]});
        dl[root] = dl[lc] == mid - l ? dl[lc] + dl[rc] : dl[lc];
        dr[root] = dr[rc] == r - mid ? dr[rc] + dr[lc] : dr[rc];
    }
    
    array<int, 3> query(int root, int l, int r, int ql, int qr) {
        if (r <= qr) {
            return {dat[root], dl[root], dr[root]};
        }

        int lc = root * 2, rc = root * 2 + 1;
        int mid = (l + r) / 2;
        array<int, 3> ans;
        if (qr <= mid) return query(lc, l, mid, ql, qr);
        else if (mid <= ql) return query(rc, mid, r, ql, qr);   
        else {
            array<int, 3> ansl = {dat[lc], dl[lc], dr[lc]};
            array<int, 3> ansr = query(rc, mid, r, ql, qr);
            ans[0] = max({ansl[0], ansr[0], ansl[2] + ansr[1]});
            ans[1] = ansl[1] == mid - l ? ansl[0] + ansr[1] : ansl[1];
            ans[2] = ansr[2] == r - mid ? ansr[0] + ansl[2] : ansr[2];
            return ans;
        }
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> res;
        init();
        for (auto &vec: queries) {
            int op = vec[0];
            if (op == 1) {
                int x = vec[1];
                modify(1, 0, n, x);
            } else {
                int x = vec[1], sz = vec[2];
                res.push_back(query(1, 0, n, 0, x)[0] >= sz);
            }
        }
        return res;
    }
};
```
```c++ [平衡树+线段树]
/*
    线段树中存每一个障碍物的左边最大空间是多少
*/
class Solution {
public:
    const int n = 50010;
    vector<int> dat;

    void init(int n) {
        int bit_len = 32 - __builtin_clz(n);
        dat.resize(2 << bit_len);
    }
    
    void modify(int root, int l, int r, int idx, int val) {
        if (l == r) { // 至少一格
            dat[root] = val;
            return;
        }
        int lc = root * 2, rc = root * 2 + 1;

        int mid = (l + r) >> 1;
        if (idx <= mid) modify(lc, l, mid, idx, val);
        if (idx > mid) modify(rc, mid + 1, r, idx, val);

        dat[root] = max(dat[lc], dat[rc]);
    }
    
    int query(int root, int l, int r, int qr) {
        if (r <= qr) {
            return dat[root];
        }

        int lc = root * 2, rc = root * 2 + 1;
        int mid = (l + r) / 2;
        if (qr <= mid) return query(lc, l, mid, qr);
        return max(dat[lc], query(rc, mid + 1, r, qr));
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> res;
        int mx = 0;
        for (auto& q:queries) {
            mx = max(mx, q[1]);
        }
        init(mx);
        set<int> st{0, mx};

        for (auto &vec: queries) {
            int op = vec[0], x = vec[1];
            auto it = st.lower_bound(x);
            int pre = *prev(it);
            int nxt = *it;
            if (op == 1) {
                st.insert(x);
                modify(1, 0, mx, x, x - pre);
                modify(1, 0, mx, nxt, nxt - x);
            } else {
                int sz = vec[2];
                int max_gap = max(query(1, 0, mx, pre), x - pre);
                res.push_back(max_gap >= sz);
            }
        }
        return res;
    }
};
```

:::