# sec 03 位运算


> 位运算比较简单，只需要理解位运算中的一些性质



## 集合及其运算
> 集合操作：将 0 1 视作一个集合。设：集合A为a,集合B为b
* 交集：a & b
* 并集：a | b
* 差： a - b : a & (~b)
* 差 (b 是 a 的子集)：a ^ b
* 包含判定：a 属于 b : a&b = a 或者 a | b = b

> 创建集合 A
* n 个元素的全集 ： (1 << n) - 1
* s 的补集：~s 或者 ((1 << n) - 1) ^ s)
* **获取末尾元素的集： s & (-a)** (树状数组)

> 集合与元素的操作：设集合 A 为 s，第 i 个元素为 i
* 存在： （s >> i) & 1
* 添加： s | (1 << i)
* 删除： s & ~(1 << i)
* 删除（一定存在）：s ^ (1 << i)
* 删除末尾元素： s & (s - 1)


## 集合个数：计算二进制中 1 的个数
* [二进制中1的个数](https://www.acwing.com/problem/content/803/)
  * [code](../acwing/acwing.801.md)
* 方法1：移位 加 统计末尾1，复杂度 O(log(n))
```c++
int cnt = 0;
while (a) {

  if (a & 1) cnt++;
  a >> = 1;
}
```

* 方法2：干掉最后一个 1
  * 考虑最后的部分：*****10000 即能得到以下两种办法

```c++
while (a) {
  a -= a & (-a); // 干掉最后一个 1
  // a &= (a - 1); // 干掉最后一个 1
  cnt++;
}
```

* 方法2: 内置函数
```c++
__builtin_popcount(a)
```
## 枚举集合
* 枚举 n 个元素的集合的所有子集
```c++
for (int s = 0; s < (1 << n); s++) {
  ...
}

```

* 枚举 S 的所有非空子集
```c++
for (int sub = s; sub; sub = (sub - 1) & s) {

}

```
* 枚举 S 的所有子集，包括空集
```c++
int sub = s
do {
  ...
  sum = (sub - 1) & s;
} while(sub != s)

```

## 与的性质
> 越与越小


## 或的性质
> 越或越大
* [6360. 最小无法得到的或值](https://leetcode.cn/problems/minimum-impossible-or/description/)
   > 加深对二进制数与或运算的理解

## 异或的性质
> 


## 配合其他技巧
[0x3f 题目单](https://leetcode.cn/circle/discuss/dHn9Vk/)