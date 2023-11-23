typedef unsigned long long ULL;
class Solution {
 public:
  bool isFlipedString(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    s1 += s1;
    int n = s1.size();
    vector<ULL> h(n + 1), p(n + 1);
    ULL base = 13131;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
      h[i] = h[i - 1] * base + (s1[i - 1] - 'a');
      p[i] = p[i - 1] * base;
    }
    ULL cp = 0;
    for (int i = 0; i < s2.size(); i++) {
      cp = cp * base + s2[i] - 'a';
    }
    int len = s2.size();
    for (int i = len; i <= n; i++) {
      ULL hp = h[i] - h[i - len] * p[len];
      if (hp == cp) return true;
    }
    return false;
  }
};
