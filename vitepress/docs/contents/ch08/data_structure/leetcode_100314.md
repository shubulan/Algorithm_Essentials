```c++
class Solution {
public:
    const int n = 50010;
    vector<int> dat, dl, dr;
    
    void build_tree(int root, int l, int r) {
        if (l == r) {
            dat[root] = dl[root] = dr[root] = 0;
            return;
        }
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
        dat.resize(n * 4);
        dl.resize(n * 4);
        dr.resize(n * 4);
        build_tree(1, 0, n);
    }
    
    void modify(int root, int l, int r, int idx) {
        if (l == r) {
            dat[root] = dl[root] = dr[root] = 0;
            return;
        } else if (l + 1 == r) {
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
    
    vector<int> query(int root, int l, int r, int ql, int qr) {
        // cout << root << " " << l << " " << r << " " << ql << " " << qr << " " << endl;
        if (l >= ql && r <= qr) {
            // cout << l << " " << r << "t" << ql << qr << "t" << dat[root] << dl[root] << dr[root] << endl;
            return {dat[root], dl[root], dr[root]};
        }
        if (l + 1 == r) return {0, 0, 0};

        int lc = root * 2, rc = root * 2 + 1;
        int mid = (l + r) / 2;
        vector<int> ans(3);
        if (qr <= mid) return query(lc, l, mid, ql, qr);
        else if (mid <= ql) return query(rc, mid, r, ql, qr);   
        else {
            vector<int> ansl = query(lc, l, mid, ql, qr);
            vector<int> ansr = query(rc, mid, r, ql, qr);
            ans[0] = max({ansl[0], ansr[0], ansl[2] + ansr[1]});
            ans[1] = ansl[1] == mid - l ? ansl[0] + ansr[1] : ansl[1];
            ans[2] = ansr[2] == r - mid ? ansr[0] + ansl[2] : ansr[2];
            // cout << l << " " << r << " " << ql << qr << "x" << ans[0] << "x" << ans[1] << "x" << ans[2] << endl;
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