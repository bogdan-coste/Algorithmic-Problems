#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<double> averageOfLevels(TreeNode* root) {

      std::vector<double> result;
      if(!root) return result;

      std::queue<TreeNode*> pq;
      pq.push(root);

      while(!pq.empty()){

        int levelSize = pq.size();
        double levelSum = 0.0;

        for(int i = 0; i < levelSize; i++){
          TreeNode* node = pq.front();
          pq.pop();
          levelSum += node -> val;
          if(node -> left) pq.push(node -> left);
          if(node -> right) pq.push(node -> right);
        }

        result.push_back(levelSum/levelSize);
      }

      return result;
    }

};

int main() {

  return 0;
}
