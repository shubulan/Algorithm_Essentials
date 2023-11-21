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

vector<int> get(string s) {
    vector<int> num;
    for (auto c : s) num.push_back(c - '0');
    reverse(num.begin(), num.end());
    return num; 
}

bool cmp(vector<int> &num1, vector<int> &num2) { // num1 < num2
    if (num1.size() != num2.size()) return num1.size() < num2.size();

    int n = num1.size();
    for (int i = n - 1; i >= 0; i--) {
        if (num1[i] != num2[i]) return num1.size() < num2.size();
    }
    return false;
}

vector<int> sub(vector<int> &num1, vector<int> &num2) {
    vector<int> res;
    int i = 0;
    for (; i < num2.size(); i++) {
        int a = num1[i];
        if (a < num2[i]) {
            a += 10;
            num1[i + 1] -= 1;
        }
        res.push_back(a - num2[i]);
    }
    for (; i < num1.size(); i++) {
        if (num1[i] < 0) {
            num1[i] += 10;
            num1[i + 1] -= 1;
        }
        res.push_back(num1[i]);
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main() {
  string a, b;
  cin >> a >> b;
  vector<int> num1 = get(a), num2 = get(b);
  int f = 0;
  if (cmp(num1, num2)) {
    f = 1;
    std::swap(num1, num2);
  }
  vector<int> res = sub(num1, num2);
  
  if (f) cout << "-";

  reverse(res.begin(), res.end());
  for (auto x : res) cout << x;
  cout << endl;

  return 0;
}