class Solution {
  private:
    TreeNode* prev;

  public:
      int getMinimumDifference(TreeNode* root) {
        int min = INT_MAX;
        prev = nullptr;
        inorder(root, min);
        return min;
      }

      void inorder(TreeNode* root, int& min){

        if(!root) return;

        inorder(root -> left, min);

        if(prev != nullptr){
          if(std::abs(root -> val - prev -> val) < min){
            min = std::abs(root -> val - prev -> val);
          }
        }

        prev = root;

        inorder(root -> right, min);

      }
};
