#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

class Solution {

  public:

    std::vector<std::string> generateParenthesis(int n){
        std::vector<std::string> collection;
        std::string current;
        generate(collection, current, 0, 0, n);

        return collection;
    }

    void generate(std::vector<std::string>& collection, std::string& current, int openBr, int closedBr, int length){

      if(openBr == closedBr && openBr == length){
          collection.push_back(current);
          return;
      }

      if(openBr < length){
          current.push_back('(');
          generate(collection, current, openBr + 1, closedBr, length);
          current.pop_back();
      }

      if(closedBr < openBr){
          current.push_back(')');
          generate(collection, current , openBr, closedBr + 1, length);
          current.pop_back();
      }
    }
};

int main() {

  int length;
  std::cin >> length;

  Solution solution;

  for(const auto& elem: solution.generateParenthesis(length)){
    std::cout << elem << std::endl;
  }
  return 0;
}
