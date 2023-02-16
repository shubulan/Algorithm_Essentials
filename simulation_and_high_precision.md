# 高精度

## 高精度加法模板

相关题目：
* P1601

```c++
/**
 * A B是两个高精度正整数
 * t 是某一位的和
 * 每次循环完成后，t保存上一次加法的进位
*/
vector<int> add(const vector<int>& A, const vector<int> &B) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size() || i < B.size(); i++) {
    if (i < A.size()) t += A[i];
    if (i < B.size()) t += B[i];
    C.push_back(t % 10);
    t /= 10;
  }
  if (t) C.push_back(t);
  return C;
}

```
## 高精度减法模板


## 高精度乘法模板

相关题目
* P1303
```
/** 高精度乘以低精度
 * 考虑到b可能为0，导致结果后大量前缀0
 * 在最后将前缀0去掉
*/
vector<int> mul(vector<int>& A, int b) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size() || t; i++) {
    if (i < A.size()) t += b * A[i];
    C.push_back(t % 10);
    t /= 10;
  }
  while (C.size() > 1 && C.back() == 0) C.pop_back();
  return C;
}

/** 高精度乘以高精度
 * 先利用高精度乘以低精度预处理，计算出0~9乘以A的结果，
 * 然后通过在末尾补0的再相加的方式，计算A * B
*/
vector<int> mul(vector<int>& A, vector<int>& B) {
  vector<int> C;
  vector<vector<int>> tb(1);
  for (int i = 1; i < 10; i++) {
    tb.push_back(mul(A, i));
  }

  for (int i = 0; i < B.size(); i++) {
    if (B[i] == '0') continue;
    C = add(C, padding_z(tb[B[i]], i));
  }
  while(C.back() == 0 && C.size() > 1) C.pop_back();
  return C;
}
```

## 高精度除法模板
