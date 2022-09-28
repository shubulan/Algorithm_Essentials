/*************************************************************************
	> File Name: euler1.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Thu 29 Oct 2020 07:29:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
typedef long long LL;
int main() {
    LL a = 1, b = 2, sum = 2;
	for (int i = 3; i <= 4000000; i++) {
		LL c = a + b;
		if (c > 4000000) break;
		if (!(c % 2)) sum += c;
		a = b;
		b = c;
	}
	cout << sum << endl;
    return 0;
}
