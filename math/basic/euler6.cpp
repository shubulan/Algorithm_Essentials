/*************************************************************************
	> File Name: euler6.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Thu 29 Oct 2020 08:00:00 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {

    int sum = 0, ssum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
        ssum += i * i;
    }
    cout << sum * sum - ssum << endl;

    return 0;
}
