# 排序
[洛谷题单](https://www.luogu.com.cn/training/107)
## 快速排序
快速排序模板
* P117
```c++
/** 快速排序
 * 可以证明(考虑两个元素的数组)，以下划分方式，可以保证
 * [l, j]的值，均<= x
 * [j + 1, r]的值，均 >= x
 * j != r
 * 但是，不对 j 和 j + 1位置的值做任何保证
*/
void quick_sort(vector<int>& arr, int l, int r) {
  if(l >= r) return;
  int i = l - 1, j = r + 1, x = arr[(l + r) >> 1];
  while (i < j) {
    do i++; while (arr[i] < x);
    do j--; while (arr[j] > x);
    if (i < j) swap(arr[i], arr[j]);
  }
  quick_sort(arr, l, j);
  quick_sort(arr, j + 1, r);
}
```

求nth_element
* P1923
```c++
/** 这里的划分写法更标准
 * [l, j]的值，均<= x
 * [j + 1, r]的值，均 >= x
 * j != r
 * j位置必为x
*/
int nth_element(vector<int> &arr, int l, int r, int k) {
  int i = l, j = r + 1, x = arr[l];
  while (i <= j) {
    do i++; while (i <= r && arr[i] < x);
    do j--; while (arr[j] > x);
    if (i <= j)
      swap(arr[i], arr[j]);
  }
  swap(arr[l], arr[j]);
  if (j == k) return arr[k];
  else if (j < k) return nth_element(arr, j + 1, r, k);
  else return nth_element(arr, l, j - 1, k);
}
```


字符串比较

优先按照字典序比较
如果一个串是另一个串的前缀，则长的大
* P1781
* [P1012](greedy\P1012.cpp)  经典排序，考察贪心



## 归并排序
归并排序模板

* [逆序堆的数量]