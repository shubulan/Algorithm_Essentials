#include <iostream>
#include <string>
using namespace std;

#define MAX_N 200
#define MAX_S 200000
string sset[MAX_N + 5];
int dp[MAX_S + 5];
string str;
int cnt;

int ook(int i, int j) {
    string &s = sset[j];
    if (s.size() > i || dp[i - s.size()] == 0) return 0;
    for (int p = s.size() - 1, q = i - 1; p >= 0; p--, q--) {
        if (s[p] != str[q]) return 0;
    }
    return 1;
}

int ok(int i) {
    for (int j = 0; j < cnt; j++) {
        if (ook(i, j)) return 1;
    }
    return 0;
}

int main() {
    while (cin >> sset[cnt]) {
        if(sset[cnt] == ".") {
            break;
        }
        cnt++;
    }
    string t;
    while (cin >> t) str += t;
    dp[0] = 1;
    int res = 0;
    for (int i = 1; i <= str.size(); i++) {
        if (dp[i] = ok(i)) {
            res = i;
        }
    }
    cout << res << endl;


    return 0;
}

