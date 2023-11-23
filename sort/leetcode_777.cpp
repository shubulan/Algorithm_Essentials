class Solution {
 public:
  bool canTransform(string start, string end) {
    int n = start.size();
    int i = 0, j = 0;
    for (; i < n; i++) {
      if (start[i] == 'X') continue;
      // 从end中找到下一个不是X的数
      while (j < n && end[j] == 'X') j++;
      if (j == n) return false;
      if (start[i] != end[j]) return false;
      if (start[i] == 'R' && i > j) return false;
      if (start[i] == 'L' && i < j) return false;
      j++;
    }
    // 遍历end字符串剩余的字符
    for (int i = j; i < n; i++)
      if (end[i] != 'X') return false;
    return true;
  }
};