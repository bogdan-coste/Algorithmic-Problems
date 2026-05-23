#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <unordered_set>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        std::unordered_map<std::string, int> distStart, distEnd;
        std::queue<std::string> qStart, qEnd;
        distStart[beginWord] = 1;
        distEnd[endWord] = 1;
        qStart.push(beginWord);
        qEnd.push(endWord);

        while (!qStart.empty() && !qEnd.empty()) {
            if (qStart.size() <= qEnd.size()) {
                int levelSize = qStart.size();
                for (int i = 0; i < levelSize; ++i) {
                    std::string curr = qStart.front(); qStart.pop();
                    int steps = distStart[curr];
                    for (int j = 0; j < curr.size(); ++j) {
                        char original = curr[j];
                        for (char c = 'a'; c <= 'z'; ++c) {
                            if (c == original) continue;
                            std::string next = curr;
                            next[j] = c;
                            if (wordSet.count(next)) {
                                if (distEnd.count(next))
                                    return steps + distEnd[next];
                                if (!distStart.count(next)) {
                                    distStart[next] = steps + 1;
                                    qStart.push(next);
                                }
                            }
                        }
                    }
                }
            } else {
                int levelSize = qEnd.size();
                for (int i = 0; i < levelSize; ++i) {
                    std::string curr = qEnd.front(); qEnd.pop();
                    int steps = distEnd[curr];
                    for (int j = 0; j < curr.size(); ++j) {
                        char original = curr[j];
                        for (char c = 'a'; c <= 'z'; ++c) {
                            if (c == original) continue;
                            std::string next = curr;
                            next[j] = c;
                            if (wordSet.count(next)) {
                                if (distStart.count(next))
                                    return steps + distStart[next];
                                if (!distEnd.count(next)) {
                                    distEnd[next] = steps + 1;
                                    qEnd.push(next);
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};

int main() {

  return 0;
}
