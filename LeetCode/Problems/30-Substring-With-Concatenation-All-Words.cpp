class Solution {
  public: vector < int > findSubstring(string s, vector < string > & words) {
    if (s.empty() || words.empty()) return {};
    int wl = words[0].size();
    int wn = words.size();
    int total = wl * wn;
    if (s.size() < total) return {};

    unordered_map < string_view, int > need;
    for (const auto & w: words) need[string_view(w)]++;

    vector < int > result;

    for (int start = 0; start < wl; ++start) {
      int left = start;
      int matched = 0;
      unordered_map < string_view, int > seen;

      for (int right = start; right + wl <= s.size(); right += wl) {
        string_view word(s.data() + right, wl);
        auto it = need.find(word);
        if (it != need.end()) {
          int & cnt = seen[word];
          cnt++;
          matched++;

          while (cnt > it -> second) {
            string_view leftWord(s.data() + left, wl);
            int & leftCnt = seen[leftWord];
            leftCnt--;
            matched--;
            left += wl;
          }

          if (matched == wn) {
            result.push_back(left);
            string_view leftWord(s.data() + left, wl);
            seen[leftWord]--;
            matched--;
            left += wl;
          }

        } else {
          seen.clear();
          matched = 0;
          left = right + wl;
        }
      }
    }
    return result;
  }
};
