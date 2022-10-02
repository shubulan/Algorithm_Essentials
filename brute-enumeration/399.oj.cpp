/*************************************************************************
	> File Name: 399.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Wed 18 Nov 2020 06:08:42 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y, step;
};
queue<node> que;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[505][505];
int n, m, sx, sy;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j]; 
            if (mmap[i][j] == '2') {
                que.push((node){i, j, 0}); 
            } 
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '3') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.') {
                que.push((node){x, y, temp.step + 1});
                mmap[x][y] = 0;
            }
        }
    }

    cout << -1 << endl;


    return 0;
}
