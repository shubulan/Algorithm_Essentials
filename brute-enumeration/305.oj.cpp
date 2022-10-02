/*************************************************************************
	> File Name: 305.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Fri 20 Nov 2020 11:17:49 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y, step;
};

int n, m, sx, sy, ans;

int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
char mmap[105][105];

int main() {
    cin >> m >> n >> sy >> sx;
    sx = n - sx + 1;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    queue<node> que;
    que.push((node){sx, sy, 0});
    mmap[sx][sy] = 0;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '.') {
                mmap[x][y] = 0;
                ans = temp.step + 1;
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cout << ans << endl;






    return 0;
}
