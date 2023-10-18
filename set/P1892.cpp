#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
/**
 * 需要理解清题意：
 * 什么叫是团体当且仅当是朋友？就是说：
 * 是朋友，一定在一个团体。
 * 在团体的各位一定是朋友
 * 
 */
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1005;
int n, m, res;
int par[N];
vector<int> enmi[N];
int find(int x) {return x == par[x] ? x : par[x] = find(par[x]);}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	par[x] = y;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) par[i] = i;
	for (int i = 0; i < m; i++) {
		char a;
		int b, c;
		cin >> a >> b >> c;
		if (a == 'F') {
			unite(b, c);
		} else {
			for (int i = 0; i < enmi[c].size(); i++) { // 为什么可以变做边处理？只处理现在即可，后面的关系，后面会处理
				unite(b, enmi[c][i]);
			}
			for (int i = 0; i < enmi[b].size(); i++) { // 为什么可以变做边处理？只处理现在即可，后面的关系，后面会处理
				unite(c, enmi[b][i]);
			}
			enmi[c].push_back(b);
			enmi[b].push_back(c);
		}
	}
	for (int i = 1; i <= n; i++) if (par[i] == i) res++;
	printf("%d\n", res);
	return 0;
}