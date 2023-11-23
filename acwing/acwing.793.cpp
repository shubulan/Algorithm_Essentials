#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;

vector<int> get(string& s) {
  int n = s.size();
  vector<int> res;
  for (int i = n - 1; i >= 0; i--) {
    res.push_back(s[i] - '0');
  }
  return res;
}

vector<int> mul(vector<int>& num, int b) {
  vector<int> res;
  int t = 0;
  for (int i = 0; i < num.size(); i++) {
    t = num[i] * b + t;
    res.push_back(t % 10);
    t /= 10;
  }
  while (t) {
    res.push_back(t % 10);
    t /= 10;
  }
  while (res.size() > 1 && res.back() == 0) res.pop_back();
  return res;
}

int main() {
  string a;
  int b;
  cin >> a >> b;
  vector<int> num1 = get(a);  //, num2 = get(b);
  vector<int> res = mul(num1, b);
  reverse(res.begin(), res.end());
  for (auto c : res) cout << c;
  cout << endl;
  return 0;
}