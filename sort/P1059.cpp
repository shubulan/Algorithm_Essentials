// [NOIP2006 普及组] 明明的随机数
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
int main() {
    vector<int> vec;
    cin >> n;
    while (n--) {
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) {
        if (i != 0) cout << " ";
        cout << vec[i];
    }
    return 0;
}