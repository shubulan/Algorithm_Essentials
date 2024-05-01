# 组合型枚举
> 组合型枚举相当于指数型枚举固定了答案的长度

## 递归实现
### [选数](https://www.luogu.com.cn/problem/P1036)
* k 为所选长度
* [code](./code_brute_enumeration/P1036.md)
```c++
void dfs(int i, int s, int sum) {
  if (s == k) { // 选择的长度必须为 k
    if (is_prime(sum)) t++;
    return;
  }
  if (n - i + s < k) return; // 剩余的长度不够 k 了
  for (int d = i; d < n; d++) {// 从 i 开始尝试网后选
    dfs(d + 1, s + 1, sum + res[d]);
  }
  return;
}
```
## 全排列实现
* 类位运算
* [code](./code_brute_enumeration/P1036.md)
```c++
  for (int i = 0; i < n - k; i++) bits.push_back(0);
  for (int i = 0; i < k; i++) bits.push_back(1);
  do {
    int sum = 0;
    for (int i = 0; i < n; i++)
      if (bits[i]) sum += res[i];
    if (is_prime(sum)) t++;

  } while (next_permutation(bits.begin(), bits.end()));
```

## 位运算实现
```c++
int comb = (1 << k) - 1;
while (comb < 1 << n) {
    // 集合处理

    int x = comb & -comb, y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
}
```
