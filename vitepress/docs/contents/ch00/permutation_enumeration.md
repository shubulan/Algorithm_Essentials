# 全排列枚举

全排列有两种方式实现，一种是dfs，一种是用c++标准库next_permutation.
获取全排列的复杂度就有n!如果用next_permutation，需要再乘以n。
10!就已经到300w的量级了。所以数据量不会大一般就1~10.

模板题目: [全排列问题](https://www.luogu.com.cn/problem/P1706)

## dfs 实现

* [code](./code_brute_enumeration/P1706)

## 标准库实现

```c++
  for (int i = 1; i <= n; i++) {
    tmp.push_back(i);
  }
  do {
    for (int i = 0; i < n; i++) {
      cout << "    " << tmp[i];
    }
    cout << endl;
  } while(next_permutation(tmp.begin(), tmp.end()));
```