#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, t;

vector<int> res, bits;

unordered_map<int, int> dict;

int is_prime(int n) {
    if (dict.count(n)) return dict[n];
    int b = 1;
    for (int i = 2; i * i < n; i++) {
        if (!(n % i)) {
            b = 0;
            break;
        }
    }
    return dict[n] = b;
}

void dfs(int i, int s, int sum) {
    if (s == k) {
        if (is_prime(sum)) t++;
        return ;
    }
    if (n - i + s < k) return;
    for (int d = i; d < n; d++) {
        dfs(d + 1, s + 1, sum + res[d]);
    }
    return ;
}
int main() {
    cin >> n >> k;
    int a;
    for (int i = 0; i < n; i++) cin >> a, res.push_back(a);
    // dfs(0, 0, 0);
    // cout << t << endl;
    for (int i = 0; i < n - k; i++) bits.push_back(0);
    for (int i = 0; i < k; i++) bits.push_back(1);
    do {
        int sum = 0;
        for (int i = 0; i < n; i++) if (bits[i]) sum += res[i];
        if (is_prime(sum)) t++;

    } while (next_permutation(bits.begin(), bits.end()));
    cout << t;

    return 0;
}

