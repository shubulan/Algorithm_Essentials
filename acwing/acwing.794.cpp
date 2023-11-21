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

vector<int> get(string a) {
    vector<int> res;
    int n = a.size();
    for (int i = n - 1; i >= 0; i--) res.push_back(a[i]-'0');
    return res;
}

vector<int> div(vector<int>& A, int b, int &r) {
    vector<int> res;
    r = 0;
    int n = A.size();
    for (int i = n - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        res.push_back(r / b);
        r %= b;
    }

    reverse(res.begin(), res.end());

    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main() {
    string a;
    int b, r;
    cin >> a >> b;
    vector<int> num = get(a);
    vector<int> res = div(num, b, r);
    reverse(res.begin(), res.end());
    for (auto c : res) cout << c;
    cout << endl << r << endl;


  return 0;
}