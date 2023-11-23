class Solution {
 public:
  bool equalFrequency(string word) {
    vector<int> cnt(30);
    for (auto c : word) cnt[c - 'a']++;
    // 尝试删除即可
    for (int i = 0; i < 30; i++) {
      if (cnt[i] != 0) {
        cnt[i]--;
        if (check(cnt)) {
          return true;
        }
        cnt[i]++;
      }
    }
    return false;
  }
  bool check(vector<int> cnt) {
    int a = 0;
    for (int i = 0; i < 30; i++) {
      if (cnt[i] == 0) continue;
      if (a == 0) a = cnt[i];
      if (a != cnt[i]) return false;
    }
    return true;
  }
};