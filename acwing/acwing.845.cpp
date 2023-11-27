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
unordered_map<string, bool> st;
string s;

vector<string> get(string &s) {
    int x;
    for (x = 0; x < s.size(); x++) {
        
    }
}

void bfs() {
  st[s] = true;
  queue<string> que;
  que.push(s);
  int t = 0;
  while (!que.empty()) {
    int sz = que.size();
    for (int i = 0; i < sz; i++) {
      string g = que.front();
      if (g == "12345678x") {
        cout << t << endl;
        return;
      }
      for (int )

    }
    t++;
  }
}

int main() {
  cin >> s;
  bfs();
  

  return 0;
}