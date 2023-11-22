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
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;


// 0 号位置默认头结点写法
int e[N], nx[N], pv[N], head, cnt;

void insertL(int k, int x) {
    e[++cnt] = x;
    nx[cnt] = k;
    pv[cnt] = pv[k];
    pv[k] = cnt;
    nx[pv[cnt]] = cnt;
}

void insertR(int k, int x) {
    e[++cnt] = x;
    nx[cnt] = nx[k];
    pv[cnt] = k;
    pv[nx[k]] = cnt;
    nx[k] = cnt;
}

void erase(int k) {
    nx[pv[k]] = nx[k];
    pv[nx[k]] = pv[k];
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    switch (c) {
    case 'R': {
        int x;
        cin >> x;
        insertL(0, x);
        break;
    }
    case 'D': {
        int k;
        cin >> k;
        erase(k);
        break;
    }
    case 'L': {
        int x;
        cin >> x;
        insertR(0, x);
        break;
    }
    case 'I': {
        char d;
        int k, x;
        cin >> d >> k >> x;

        if (d == 'R') {
            insertR(k, x);
        } else {
            insertL(k, x);
        }
    }
    }
  }
  for (int i = nx[head]; i != head; i = nx[i]) {
    cout << e[i] << " ";
  }
  cout << endl;


  return 0;
}