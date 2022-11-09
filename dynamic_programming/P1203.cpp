#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_N 350
int dpl[MAX_N * 2 + 5];
int dpr[MAX_N * 2 + 5];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    s += s;

    dpl[0] = 1;
    char cur = s[0];
    int wc = 0;
    if (cur == 'w') wc++;
    //cout << s << endl;
    for (int i = 1; i < n * 2; i++) {
        if (cur == 'w' || s[i] == cur || s[i] == 'w') {
            dpl[i] = dpl[i - 1] + 1;
        } else {
            dpl[i] = 1 + wc;
        }
        if (s[i] != 'w') {
            cur = s[i];
            wc = 0;
        } else {
            wc++;
        }

    }

    cur = s[n * 2 - 1];
    dpr[n * 2 - 1] = 1;
    wc = 0;
    if (cur == 'w') wc++;
    for (int i = n * 2 - 2; i >= 0; i--) {
        if (cur == 'w' || s[i] == cur || s[i] == 'w') {
            dpr[i] = dpr[i + 1] + 1;
        } else {
            dpr[i] = 1 + wc;
        }
        if (s[i] != 'w') {
            cur = s[i];
            wc = 0;
        } else {
            wc++;
        }
    }

    int res = 0;
    for (int i = n - 1, j = 0; j <  n; i++, j++) {
        res = max(dpl[i] + dpr[j], res);
    }
    cout << min(res, n) << endl;

    return 0;
}

