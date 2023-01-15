#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <string>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef __int128 LLL;
LL gcd(LL a, LL b) {
  if (!b) return a;
  return gcd(b, a % b);
}
bool is_prime(LL N) {
  for (LL i = 0; i * i <= N; i++) {
    if (N % i == 0) return false;
  }
  return true;
}
template <class T>
T randint(T l, T r = 0) // 生成随机数建议用<random>里的引擎和分布，而不是rand()模数，那样保证是均匀分布
{
  static random_device rd;
  static mt19937 eng(rd());
  if (l > r)
      swap(l, r);
  uniform_int_distribution<T> dis(l, r);
  return dis(eng);
}
LL Pollard_Rho(LL N)
{
    if (N == 4)
        return 2;
    if (is_prime(N))
        return N;
    while (1)
    {
        LL c = randint(1LL, N - 1);
        auto f = [=](LL x) { return ((LLL)x * x + c) % N; };
        LL t = 0, r = 0, p = 1, q;
        do
        {
            for (int i = 0; i < 128; ++i) // 令固定距离C=128
            {
                t = f(t), r = f(f(r));
                if (t == r || (q = (LLL)p * abs(t - r) % N) == 0) // 如果发现环，或者积即将为0，退出
                    break;
                p = q;
            }
            LL d = gcd(p, N);
            if (d > 1)
                return d;
        } while (t != r);
    }
}

const int TIMES=10;

LL Quick_Mul(LL a,LL b,LL p) {
	LL tmp=(a*b-(LL)((long double)a/p*b+1e-8)*p);
	if(tmp<0)return tmp+p;
	else return tmp;
}

LL Quick_Pow(LL a,LL b,LL p) {
	LL sum=1;
	for(a%=p; b; b>>=1,a=Quick_Mul(a,a,p))if(b&1)sum=Quick_Mul(sum,a,p);
	return sum;
}

mt19937 g(rand());

bool Witness(LL a,LL n) {
	LL u=n-1,t=0;
	while(u%2==0)t++,u>>=1;
	LL x=Quick_Pow(a,u,n);
	if(x==1)return false;
	for(int i=1; i<=t; i++,x=Quick_Mul(x,x,n))
		if(x!=n-1&&x!=1&&Quick_Mul(x,x,n)==1)return true;
	return x!=1;
}

bool Miller_Rabin(LL n) {
	if(n==2)return true;
	if(n<2||!(n&1))return false;
	for(int i=1; i<=TIMES; i++)
		if(Witness(g()%(n-1)+1,n))return false;
	return true;
}

LL Pollar_Rho(LL n) {
	if(!(n&1))return 2;
	while(true) {
		LL a=g()%(n-1)+1,b=a,c=g()%(n-1)+1;
		if(c==2)c=3;
		while(true) {
			a=(Quick_Mul(a,a,n)+c)%n;
			b=(Quick_Mul(b,b,n)+c)%n;
			b=(Quick_Mul(b,b,n)+c)%n;
			if(a==b)break; //环
			LL d=__gcd(abs(b-a),n);
			if(d>1)return d;
		}
	}
}

LL Find_Fac(LL n) { //找出最小因子
	if(Miller_Rabin(n))return n;
	LL p=Pollar_Rho(n);
	return min(Find_Fac(p),Find_Fac(n/p));
}

LL x, T;
int main() {
  cin >> T;
  while (T--) {
    cin >> x;
    //int r = is_prime(x);
    LL r = Pollar_Rho(x);
    if (r == x) cout << "Prime" << endl;
    else cout << r << endl;
  }

  return 0;
}