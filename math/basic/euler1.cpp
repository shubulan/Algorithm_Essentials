/*************************************************************************
	> File Name: euler1.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Thu 29 Oct 2020 07:29:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (!(i % 3) || !(i % 5) )
            sum += i;
    }
    cout << sum << endl;
    return 0;
}
