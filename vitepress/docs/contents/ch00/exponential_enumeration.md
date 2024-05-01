# 指数型枚举
指数型枚举往往用于枚举一个集合的所有子集

## 递归实现
### [235. 递归实现指数型枚举](https://oj.haizeix.com/problem/235)
实现方式1
* 选还是不选
    * 缺点：无法按照字典序获得结果
```c++
void dfs(int idx) {
    if (idx == n) {
        print()
        return;
    }
    dfs(idx + 1); // 不选

    nums[cnt++] = idx; // 选
    dfs(idx + 1);
    cnt--; // 恢复
}
```
实现方式2
* 当前选谁 
    * 通过先选小数的方式，实现字典序遍历
* [code1](./code_brute_enumeration/235.oj.md)
* [code2](./code_brute_enumeration/235_2.oj.md)

## 位运算实现
> 位运算的经典技巧，比如枚举 n 个元素的所有子集
```c++
for (int s = 0; i < (1 << n); i++) {
    // s 的每一位代表一个元素
}
```
## 位运算实现2
> 枚举 S 代表的集合的所有子集 [见 位运算](../ch02//bitwise_operation)
