/*************************************************************************
        > File Name: 395.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Mon 02 Nov 2020 04:19:45 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int n, k;
int num[1000];
int line[1000];
int func(int len) {
  int cnt = 0;
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (now + num[i] > len) {
      cnt++;
      now = num[i];
    } else if (now + num[i] == len) {
      cnt++;
      now = 0;
    } else {
      now += num[i];
    }
  }
  if (now) cnt++;
  return cnt;
}

int main() {
  cin >> n >> k;
  int r = 0;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    r += num[i];
  }
  int l = 0;

  while (l != r) {
    int mid = (l + r) / 2;
    int s = func(mid);
    if (s <= k) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  int now = 0;
  for (int i = n - 1, j = 2 * k; i >= 0; i--) {
    if (now == 0) {  // 开始新的人
      line[j] = i + 1;
      j--;
    }
    if (now + num[i] > l) {  // 知道了一个越界
      line[j] = i + 2;       // 一个人的结尾
      line[j - 1] = i + 1;   // 另一个人的开始
      j -= 2;
      now = num[i];  // 新一个人的开始
    } else if (now + num[i] == l) {
      line[j] = i + 1;  // 一个人的结尾
      // line[j+1] = i; //另一个人的开始不用写了,结合在了now=0这里
      j--;
      now = 0;
    } else {
      now += num[i];  // 其他正常加
    }
  }
  if (now) line[1] = 1;
  for (int i = 1; i <= k; i++) {
    cout << line[2 * i - 1] << " " << line[2 * i] << endl;
  }
  return 0;
}
