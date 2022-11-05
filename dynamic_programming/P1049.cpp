#include <iostream>

using namespace std;
#define MAX_N 20000
int dp[MAX_N + 5];
int n, V;
int main() {
    dp[0] = 1;
    cin >> V >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        for (int j = V; j >= x; j--) {
            if (dp[j - x]) dp[j] = dp[j - x];
        }
    }
    for (int i = V; i >= 0; i--) 
        if (dp[i] != 0) {
            cout << V - i << endl;
            break;
        }

    return 0;
}