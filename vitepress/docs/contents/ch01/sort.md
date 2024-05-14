# sec01 排序
[[toc]]

## 快速排序
要点：
* 什么时候会发生无限递归：当分割点等于 l 或者 r 的时候，会发生深层调用参数一致的情况
* 循环不变量：$[l, i] <= x， [l, j] >= x$。结束时，保证
  * $[l, j] <= x, [j + 1, r] >= x$
  * $[l, i - 1] <= x, [i, r] >= x$
* 所以选哪个都行，但是如果选 $i$ 作为 分割点会无限递归
* 当仅有两个元素时，中间的数选择的是左边 0 号元素。所以 i 会留在 l 的位置。j 也会留在 l 的位置。
* 此时选择 i 作为分割点，右半边是 $[i, r] == [l, r]$， 所以会发生死递归

```c++
void qsort(int* arr, int l, int r) {
  if (l >= r) return;
  int x = arr[l + r >> 1], i = l - 1, j = r + 1;
  while (i < j) {
    do i++;
    while (arr[i] < x);
    do j--;
    while (arr[j] > x);
    if (i < j) swap(arr[i], arr[j]);
  }
  // 代码到这里，j 位置保证 <= x。保证[l, j] <= x
  qsort(arr, l, j);  
             // 此外，保证了 j != r, 保证 [l, j] != [l, r] 不会导致死循环
  qsort(arr, j + 1, r);
}
```

## 变体: 第 k 个值
要点：递归结束条件还是挺巧妙的
```
int kth_num(int *arr, int l, int k, int r) {
  if (l == r) {
    return arr[l];
  }
  int x = arr[l + r >> 1], i = l - 1, j = r + 1;
  while (i < j) {
    do i++;
    while (arr[i] < x);
    do j--;
    while (arr[j] > x);
    if (i < j) swap(arr[i], arr[j]);
  }

  if (k <= j) return kth_num(arr, l, k, j);
  else return kth_num(arr, j + 1, k, r);
}

```

## 归并排序
要点：
* 归并排序是分治思想的典型应用，在归并的过程中，很像线段树的合并两段信息
* 归并排序也是一种双指针
* 归并排序需要额外的空间
* 归并有两种写法：
  * 三个循环写法：保证两数组都有值才比较
  * 一个循环写法：将某个数组为空纳入判断条件，默认++另一个数组
* 作用：求逆序对

::: code-group
```c++ [三个循环]
void merge_sort(int* arr, int l, int r) {
  if (l >= r) return;

  int mid = (l + r) >> 1;
  merge_sort(arr, l, mid);
  merge_sort(arr, mid + 1, r);
  int i = l, j = mid + 1, idx = 0;

  while (i <= mid && j <= r)
    if (arr[j] < arr[i]) temp[idx++] = arr[j++];
    else temp[idx++] = arr[i++];
  while (i <= mid) temp[idx++] = arr[i++];
  while (j <= r) temp[idx++] = arr[j++];

  for (int i = l, j = 0; i <= r; i++) 
    arr[i] = temp[j++];
}
```
```c++ [一个循环]
void merge_sort(int* arr, int l, int r) {
  if (l >= r) return;

  int mid = (l + r) >> 1;
  merge_sort(arr, l, mid);
  merge_sort(arr, mid + 1, r);
  int i = l, j = mid + 1, idx = 0;

  while (i <= mid || j <= r) { // 写法2
    if (i > mid || (j <= r && arr[j] < arr[i]))
      temp[idx++] = arr[j++];
    else temp[idx++] = arr[i++];
  }
  for (int i = l, j = 0; i <= r; i++) 
    arr[i] = temp[j++];
}
```
:::

* 例题 [2426. 满足不等式的数对数目](https://leetcode.cn/problems/number-of-pairs-satisfying-inequality/)
  * 求逆序对的变体。
  * 求逆序对还可以用树状数组 + 二分来求解，时间复杂度 $O(nlog(n)log(n))$

```c++
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        for (int i = 0; i < n; i++) nums1[i] -= nums2[i];
        return merge_sort(nums1, 0, n - 1, diff);
    }
    long long merge_sort(vector<int>& nums, int l, int r, int diff) {
        static vector<int> tp(100005);
        if (l >= r) {
            return 0;
        }
        int mid = (l + r) / 2;
        long long res = 0;
        res += merge_sort(nums, l, mid, diff);
        res += merge_sort(nums, mid + 1, r, diff);
        for (int i = l, j = mid + 1; i <= mid; i++) {
            while (j <= r && nums[j] + diff < nums[i]) j++;
            res += r - j + 1;
        }
        int n = r - l + 1;
        
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) tp[k++] = nums[i++];
            else tp[k++] = nums[j++];
        }
        while (i <= mid) tp[k++] = nums[i++];
        while (j <= r) tp[k++] = nums[j++];
        for (int i = l; i <= r; i++) nums[i] = tp[i - l];
        return res;
    }
};
```
## 排序题目
* [大统领投票](https://oj.haizeix.com/problem/380)
  * [code](./code_sort/380.oj)
* [谁拿了最多奖学金](https://oj.haizeix.com/problem/381)
  * [code](./code_sort/381.oj)
* [明明的随机数](https://www.luogu.com.cn/problem/P1059)
  * [排序与去重](./code_sort/P1059)

## 排序与贪心
> 排序问题通常跟贪心问题结合在一起。因为贪心就是有序的选择。
> 
> 贪心很难证明，都是靠感觉猜出来的，即使这道比较简单的题，很容易感觉它是对的，但是仍然很难**想到这个思路**并且**证明它**

例题：[拼数](https://www.luogu.com.cn/problem/P1012)

### 数字与字典序
* 同长度下，数字比较和字典序比较是一样的
* 不同长度下，
  * 长度更长的数字一定大，而字典序不一定
  * 数字大的字典序不一定大
  * 字典序更大的数字也不一定大
### 解决
思考提示
* 最终拼成的数字长度是固定的
* 因此需要整体的*字典序最大*或者*数字最大*
* 不是字典序降序排列：反例：

`99 9900` 字典序应该是 `9900` 排在前面，而答案应该是 `99` 排在前面
* 不是数字序列排在前面：反例

`9 8888` 数字序应该是 `8888` 排在前面，而答案应该是 `9` 排在前面
* **最优解中，任意 i < j 必有 $str[i] + str[j] \ge str[j] + str[i]$**

证明：反证法

如果最优解的拼接序列中，存在 $i < j$ 并且 $str[i] + str[j] < str[j] + str[i]$
那么可以通过交换 $i j$,来使整体的字典序更大,这与最优解的结论矛盾。因此，最优解一定是这样排序的

```c++
void solve {
  string s;
  int n;
  cin >> n;
  vector<string> arr;
  for (int i = 0; i < n; i++) {
    cin >> s;
    arr.push_back(s);
  }
  sort(arr.begin(), arr.end(),
       [](string &a, string &b) { return a + b > b + a; });
  string res;
  for (auto &s : arr) res += s;
  cout << res << endl;
}
```