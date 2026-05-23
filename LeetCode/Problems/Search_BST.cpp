#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {

private:

public:

  static bool exists(TreeNode *root, int target) {

    if (!root) {
      return false;
    }

    if(root -> val == target){
      return true;
    }

    if(root -> val <= target){
      return exists(root -> right, target);
    }
        
    return exists(root -> left, target);
    
  }
};

int main() {

  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(8);

  int target = 3;
  std::cout << Solution::exists(root, target);

  return 0;
}
