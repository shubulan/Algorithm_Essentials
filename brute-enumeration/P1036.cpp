#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int n, k, t;

vector<int> res;

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
    dfs(0, 0, 0);
    cout << t << endl;


    return 0;
}

