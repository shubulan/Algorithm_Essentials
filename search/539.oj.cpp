/*************************************************************************
	> File Name: 539.oj.cpp
	> Author: shubulan
	> Mail: gaoyulong1996@163.com
	> Created Time: Tue 24 Nov 2020 11:50:53 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> vecstr;
char sign[7] = {'+', '-', '*', '/', '&', '|', '^'};
string s;
int check[4];
char temp[5];
void func(int b) {
    if (b == 4) {
        vecstr.push_back(temp);
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (check[i]) {
            continue;
        }
        temp[b] = s[i];
        check[i] = 1;
        func(b + 1);
        temp[b] = 0;
        check[i] = 0;
    } 

}
int num[4];
string generate(string s, char asign[3]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            //根据操作顺序，计算值
            //如果是24则生成该方案，并保存
        }
    }
}
int main() {
    char c;
    for (int i = 0; i < 4; i++) {
        cin >> c;
        s.push_back(c);
    }
    func(0);
    char asign[3];
    for (auto ts : vecstr) {
        for (int i = 0; i < 7; i++) {
            asign[0] = sign[i];
            for (int j = 0; j < 7; j++) {
                asign[1] = sign[j];
                for (int k = 0; k < 7; k++) {
                    asign[2] = sign[k];
                    if ((s = generate(ts, asign)) != "") {
                        cout << s << endl;
                        return 0;
                    } 
                }
            }
        } 
    }
    
    return 0;
}
