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

#define MAX_N 5000
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL arr[MAX_N + 5];

string get(const string &str) {
    vector<string> res;
    vector<int> nums;
    string s;
    int num = 0;
    for (auto c : str) {
        if (c >= 'A' && c <= 'Z') s += c;
        else if (c >= '0' && c <= '9') {
            num = num * 10 + c - '0';
        } else if (c == '[') {
            res.push_back(s);
            s = "";
            nums.push_back(num);
            num = 0;
        } else if (c == ']') {
            for (int i = 0; i < num; i++) {
                res.back() += s;
            }
            num = nums.back();
            nums.pop_back();
            s = std::move(res.back());
            res.pop_back();
        }
    }
    return s;
}

int main() {
  string s;
  cin >> s;
  cout << get(s) << endl;
  return 0;
}
