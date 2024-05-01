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

int num;
stack<int> st;
stack<char> op;
void eval() {
  char c = op.top();
  op.pop();
  int y = st.top();
  st.pop();
  int x = st.top();
  st.pop();
  switch (c) {
    case '+':
      st.push(x + y);
      break;
    case '-':
      st.push(x - y);
      break;
    case '*':
      st.push(x * y);
      break;
    case '/':
      st.push(x / y);
      break;
  }
}

int main() {
  string s;
  cin >> s;
  unordered_map<char, int> pr;
  pr['+'] = 0;
  pr['-'] = 0;
  pr['*'] = 1;
  pr['/'] = 1;
  pr['('] = -1;

  for (int i = 0; i < s.size(); i++) {
    switch (s[i]) {
      case '+':
      case '-':
      case '*':
      case '/':
        while (op.size() && pr[s[i]] <= pr[op.top()]) {
          eval();
        }
        op.push(s[i]);
        break;
      case '(': {
        op.push(s[i]);
        break;
      }
      case ')': {
        while (op.top() != '(') {
          eval();
        }
        op.pop();
        break;
      }
      default: {  // number
        int num = 0, j = i;
        while (j < s.size() && (s[j] >= '0' && s[j] <= '9')) {
          num = num * 10 + s[j++] - '0';
        }
        i = j - 1;
        st.push(num);
      }
    }
  }
  while (!op.empty()) {
    eval();
  }
  cout << st.top() << endl;

  return 0;
}