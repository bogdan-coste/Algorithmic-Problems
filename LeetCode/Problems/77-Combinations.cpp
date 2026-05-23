#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        
        std::vector<std::vector<int>> collection;
        std::vector<int> current;
        backtracking(collection, current, 1, n, k);

        return collection;

    }

    void backtracking(std::vector<std::vector<int>>& collection, std::vector<int>& current, int start, int n, int k){

        if(current.size() == k){
            collection.push_back(current);
            return;
        }

        for(int i = start; i <= n; i++){
            current.push_back(i);
            backtracking(collection, current, i + 1, n, k);
            current.pop_back();
        }
    }
};

int main() {

  return 0;
}
