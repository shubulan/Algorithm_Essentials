#include <algorithm>
#include <cassert>
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

const int N = 100005;

int son[N][26], cnt[N], idx;

void insert(const char *s) {
    int p = 0;
    while (*s) {
        int c = *s - 'a';
        if (!son[p][c]) son[p][c] = ++idx;
        p = son[p][c];
        s++;
    }
    cnt[p]++;
}

int query(const char *s) {
    int p = 0;
    while (*s) {
        int c = *s - 'a';
        if (!son[p][c]) son[p][c] = ++idx;
        p = son[p][c];
        s++;
    }
    return cnt[p];
    
}

int main() {
    // 其实哈希表就可以过，
    // unordered_map<string, int> mp;
    // int n;
    // cin >> n;
    // while (n--) {
    //     string op, s;
    //     cin >> op >> s;
    //     if (op == "I") mp[s]++;
    //     else cout << mp[s] << endl;
    // }
    // 但还是学习下 trie 树的写法
    int n;
    cin >> n;
    while (n--) {
        string op, s;
        cin >> op >> s;
        if (op == "I") insert(s.c_str());
        else cout << query(s.c_str()) << endl;
    }
    return 0;
}