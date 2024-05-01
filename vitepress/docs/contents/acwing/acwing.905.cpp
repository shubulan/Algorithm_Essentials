#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr;
    while (n--) {
        int a, b;
        cin >> a >> b;
        arr.push_back({b, a});
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    for (int i = 0, j = 0; i < arr.size(); ) {
        int e = arr[i][0];
        cnt++;
        while (j < arr.size() && arr[j][1] <= e) j++;
        i = j;
    }
    cout << cnt << endl;

    return 0;
}