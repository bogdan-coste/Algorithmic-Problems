#include <algorithm>
#include <iostream>
#include <climits>

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
    static int maxPathSum(TreeNode* root) {
        
        int maxi = INT_MIN;
        postorder(root, maxi);
        return maxi;
    }

    static int postorder(TreeNode* root, int& maxi){

        if  (!root) return 0;

        int leftGain = std::max(0, postorder(root->left, maxi));
        int rightGain = std::max(0, postorder(root -> right, maxi));

        int totalGain = leftGain + root -> val + rightGain;
        maxi = std::max(maxi, totalGain);

        return root -> val + std::max(leftGain, rightGain);
    }
};

int main() {

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::cout << Solution::maxPathSum(root);

    return 0;
}
