/*************************************************************************
	> File Name: 538.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Fri 20 Nov 2020 07:15:49 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

char mmap[25][25];
int n, check[25];
void dfs(int node) {
    if (node != 1) {
        cout << "-";
    }
    cout << node; 
    check[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (mmap[node][i] == '1' && check[i] == 0) {
            dfs(i);
        }
    }
}
int main() {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            dfs(i);
        }
    }
    cout << endl;

    return 0;
}
