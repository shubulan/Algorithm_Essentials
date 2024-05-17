
```c++
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>
#include <string>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int N = 105;
const int B = 1e9 + 7;
int n;
ULL h[105], T[105];
string s;
bool check(int m) {
  unordered_map<ULL, int> mmap;
  ULL a = 0;
  ULL t = T[m];;
  for (int i = m; i <= n; i++) {
    if (i == m) a = h[i];
    else a = a * B + s[i - 1] - s[i - 1 - m] * t;
    if (mmap.count(a)) return false;
    mmap[a]++;
  }
  return true;
}
void init() {
  T[0] = 1;
  for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] * B + s[i - 1];
    T[i] = T[i - 1] * B;
  }
}
int main() {
  cin >> n;
  cin >> s;
  init();
  int l = 1, r = n;  
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
```

```c++
/**
 * @brief 
 * 字符串哈希
 * 1. 首先要知道原理，多想几遍
 * 2. 找到比较通用的模板如下：
 */
typedef unsigned long long ULL;

const int N = 110,P=131;

int n;
char str[N];
ULL h[N],p[N];

ULL get(int l, int r)  // 计算子串 str[l ~ r] 的哈希值
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

bool check(int k)
{
    ULL l,r;
    for(int i=1;i+k-1<=n;i++)
    {
        l=get(i,i+k-1);
        for(int j=i+1;j+k-1<=n;j++)
        {
            r=get(j,j+k-1);
            if(l==r)return false;
        }
    }

    return true;
}


int main()
{
    cin >> n;
    cin >> (str+1);

    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]*P+str[i];
        p[i]=p[i-1]*P;
    }

    int l=1,r=100;
    while(l<r)
    {
        int k=l+r>>1;
        if(check(k))r=k;
        else l=k+1;
    }

    printf("%d\n",l);

    return 0;
}
```