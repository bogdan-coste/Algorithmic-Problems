#include <cstdlib>
#include <iostream>
#include <climits>

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
public:
    int kthSmallest(TreeNode* root, int k) {
        
      int min = INT_MAX;
      int k1 = k;
      inorder(root, min, k1);

      return min;
    }

    void inorder(TreeNode* root, int& min, int& k){

      if(!root || k == 0) return;


      inorder(root -> left, min, k);

      k--;

      if(k == 0){
        min = root -> val;
        return;
      }

      inorder(root -> right, min, k);

    }
};

int main() {

TreeNode* root = new TreeNode(5);
root->left = new TreeNode(3);
root->right = new TreeNode(6);
root->left->left = new TreeNode(2);
root->left->right = new TreeNode(4);
root->left->left->left = new TreeNode(1);

  int target = 6;
  Solution solution;
  std::cout << solution.kthSmallest(root, target);

  return 0;
}
