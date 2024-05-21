#include <algorithm>
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
int n;
char arr[250];
const char* ct[4] = {"ooo*o**--", "o--*o**oo", "o*o*o*--o", "--o*o*o*o"};
void print(int n) {
  for (int i = 0; i < 2 * n + 2; i++) cout << arr[i];
  cout << endl;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) arr[i] = 'o';
  for (int i = n; i < 2 * n; i++) arr[i] = '*';
  arr[2 * n] = '-';
  arr[2 * n + 1] = '-';
  int t = n;
  print(n);
  while (t--) {
    arr[2 * (t + 1)] = arr[t];
    arr[2 * (t + 1) + 1] = arr[t + 1];
    arr[t] = arr[t + 1] = '-';
    print(n);
    if (t == 3) break;
    arr[t] = arr[t + 1] = '*';
    arr[2 * t] = arr[2 * t + 1] = '-';
    print(n);
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 9; j++) arr[j] = ct[i][j];
    print(n);
  }

  return 0;
}