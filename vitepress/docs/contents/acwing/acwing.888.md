```c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> mul(vector<int> &A, int b)  // C = A * b, A >= 0, b >= 0
{
    vector<int> C;

    int t = 0;
    for (unsigned i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}
const int N = 5005;
int primes[N], cnt;
int pc[N];
bool st[N];
void get_primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (!st[i]) primes[cnt++] = i;
    for (int j = 0; primes[j] <= n / i; j++) {
      st[primes[j] * i] = 1;
      if (i % primes[j] == 0) break;
    }
  }
}

int get(int n, int p) {
  int res = 0;
  while (n) {
    res += n / p;
    n /= p;
  }
  return res;
}

int main() {
  int a, b, r;
  cin >> a >> b;
  vector<int> res{1};
  get_primes(a);
  for (int i = 0; i < cnt; i++) {
    int p = primes[i];
    pc[i] = get(a, p) - get(b, p) - get(a - b, p);
  }

  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < pc[i]; j++)
      res = mul(res, primes[i]);
  }

  reverse(res.begin(), res.end());
  for (auto x : res) cout << x;
  cout << endl;


  return 0;
}
```