#include <algorithm>
#include <iostream>

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
    static int maxDepth(TreeNode* root) {
        
        return postorder(root);
    }

    static int postorder(TreeNode* root){

        if  (!root) return 0;

        int leftCount = postorder(root->left);
        int rightCount = postorder(root -> right);

        return 1 + std::max(leftCount, rightCount);
    }
};

int main() {

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::cout << Solution::maxDepth(root);

    return 0;
}
