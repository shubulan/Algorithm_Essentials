```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        for (auto &s : tokens) {
            if (isdigit(s[0]) || (s[0] == '-' && s.size() > 1)) {
                int x = stoi(s);
                st.push_back(x);
            } else if (s == "+") {
                int x = st.back(); st.pop_back();
                int y = st.back(); st.pop_back();
                st.push_back(x + y);
            } else if (s == "-") {
                int x = st.back(); st.pop_back();
                int y = st.back(); st.pop_back();
                st.push_back(y - x);
            } else if (s == "*") {
                int x = st.back(); st.pop_back();
                int y = st.back(); st.pop_back();
                st.push_back(x * y);
            } else if (s == "/") {
                int x = st.back(); st.pop_back();
                int y = st.back(); st.pop_back();
                st.push_back(y / x);
            }
        }
        cout << st.size() << endl;
        return st.back();
    }
};
```