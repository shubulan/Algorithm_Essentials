/*************************************************************************
	> File Name: 398.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Fri 20 Nov 2020 10:33:48 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int dir[8][2] = {1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2};
struct node {
    int x, y, step;
};
int num[405][405], n, m, sx, sy;



int main() {
    memset(num, -1, sizeof(num));
    cin >> n >> m >> sx >> sy;
    num[sx][sy] = 0;
    queue<node> que;
    que.push((node){sx, sy, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > m || num[x][y] != -1) {
                continue;
            }
            num[x][y] = temp.step + 1;
            que.push((node){x, y, num[x][y]});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) {
                cout << " ";
            }
            cout << num[i][j];
        }
        cout << endl;
    }

    return 0;
}
