// P1271 【深基9.例1】选举学生会
#include<iostream>
#include <vector>
using namespace std;

int arr[1000];
int n, m;
int main() {
    cin >> n >> m;
    int c = m, x;
    while (c--) {
        cin >> x;
        arr[x]++;
    }
    
    for (int i = 1; i <= n; i++) {
        int c = arr[i];
        for (int j = 0; j < c; j++) {
            cout << i << " ";
        }
    }
    return 0;
}