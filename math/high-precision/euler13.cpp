/*************************************************************************
	> File Name: euler13.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Thu 29 Oct 2020 09:39:37 PM CST
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
int ans[105];
char s[105];
int sn[105];
void add(int n1[105], int n2[105]);
int main () {
    while (cin >> s) {
        sn[0] = strlen(s); 
        for (int i = sn[0]; i > 0; i--) {
            sn[i] = s[sn[0] - i] - '0';
        }
        add(ans, sn);
    } 
    cout << ans[0] << " : " << endl;

    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i]; 
    }
    return 0;
}
void add(int n1[105], int n2[105]) {
    n1[0] = max(n1[0], n2[0]);    
    for (int i = 1; i <= n2[0]; i++) {
        n1[i] = n1[i] + n2[i];
    }
    for (int i = 1; i <= n1[0]; i++) {
        if (n1[i] > 9) {
            n1[i + 1] += n1[i] / 10;
            n1[i]  %= 10;
            if (i == n1[0]) {
                n1[0]++;
            }
        }
    }
}
