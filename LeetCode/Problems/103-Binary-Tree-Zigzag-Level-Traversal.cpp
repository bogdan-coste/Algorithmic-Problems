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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root){

      std::vector<std::vector<int>> result;

      if(!root) return result;

      std::queue<TreeNode*> q;

      q.push(root);

      bool leftToRight = true;

      while(!q.empty()){

        int qSize = q.size();

        std::vector<int> tempRes(qSize);

        for(int i = 0; i < qSize; i++){
          TreeNode* node = q.front();
          q.pop();

          int idx = leftToRight ? i : (qSize - i - 1);
          tempRes[idx] = node -> val;

          if(node -> left) q.push(node -> left);
          if(node -> right) q.push(node -> right);
        }

        result.push_back(tempRes);
        leftToRight = !leftToRight;

      }
      return result;
    }

};

int main() {

  return 0;
}
