```c++
class Solution {
public:
    int calculate(string s) {
        stack<char> signs;
        stack<int> nums;
        int cur_num = 0;
        for (auto c : s) {
            switch (c) {
                case ' ': break;
                case ')':
                    cacl(signs, nums, cur_num);
                    signs.pop();
                    break;
                case '+':
                case '-':
                    cacl(signs, nums, cur_num);
                    nums.push(cur_num);
                    cur_num = 0;
                    // fall through
                case '(':
                    signs.push(c);
                    break;
                default:
                    cur_num = cur_num * 10 + (c - '0');
            }
        }
        cacl(signs, nums, cur_num);
        return cur_num;
    }
    void cacl(stack<char>& signs, stack<int>& nums, int& y) {
        if (signs.empty()) return;
        if (signs.top() == '(') return;
        char op = signs.top(); signs.pop();
        int tnum = nums.top(); nums.pop();
        if (op == '+')
            y = tnum + y;
        else if (op == '-')
            y = tnum - y;
    }
};
```