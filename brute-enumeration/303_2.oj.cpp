/*************************************************************************
	> File Name: 303_2.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Wed 18 Nov 2020 08:35:02 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[1005][1005];
int num[1005][1005];
int mark[1005][1005];
int func(int x, int y) {
    if (mmap[x][y] == '1') {
        return num[x][y] = 0;
    }
    if (num[x][y] != -1) {
        return num[x][y];
    }

    int temp = 2100000000;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0]; 
        int yy = y + dir[i][1];
        if (xx < 0 || yy < 0 || xx >= n || yy >= m || mark[xx][yy]) {
            continue;
        }
        mark[xx][yy] = 1;
        temp = min(temp, func(xx, yy) + 1);
    }
    return num[x][y] = temp;
}

int main() {
    cin >> n >> m;
    memset(num, -1, sizeof(num));
    for (int i = 0; i < n; i++) {
        cin >> &mmap[i][0];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mark[i][j] = 1;
            if (num[i][j] == -1) {
                func(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != 0) {
                cout << " ";
            }
            cout << num[i][j];
        }
        cout << endl;
    }
    return 0;
}
