/*************************************************************************
        > File Name: 540.oj.cpp
        > Author: shubulan
        > Mail: gaoyulong1996@163.com
        > Created Time: Tue 24 Nov 2020 10:19:34 AM CST
 ************************************************************************/

#include <algorithm>
#include <iostream>
using namespace std;

int t, arr[45], num1[1500000], cnt1;

// 折半枚举
// 枚举前N/2个数且总和小于X的总和情况，复杂为2^20 次方 1000000复杂度。
void func1(int b, int e, int num[], int now, int X) {
  if (now > X) {
    return;
  }
  for (int i = b; i <= e; i++) {
    now += arr[i];
    num[cnt1++] = now;
    func1(i + 1, e, num, now, X);
    now -= arr[i];
  }
}
// 二分查找另一半
int func2(int b, int e, int now, int X) {
  int target = X - now;
  int left = 1, right = cnt1 - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (num1[mid] == target) {
      return 1;
    } else if (num1[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  for (int i = b; i <= e; i++) {
    now += arr[i];
    if (func2(i + 1, e, now, X)) {
      return 1;
    }
    now -= arr[i];
  }
  return 0;
}

int main() {
  while (1) {
    int N, X;
    cnt1 = 0;
    cin >> N >> X;
    if (!cin) {
      break;
    }
    for (int i = 1; i <= N; i++) {
      cin >> arr[i];
    }
    func1(1, N / 2, num1, 0, X);
    sort(num1, num1 + cnt1);
    if (func2(N / 2 + 1, N, 0, X)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
