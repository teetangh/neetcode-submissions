/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diameterHelper(root,diameter);
        return diameter;
    }

    int diameterHelper(TreeNode* root, int& diameter){
        if(root == NULL)
            return 0;
        
        int leftHeight = diameterHelper(root->left,diameter);
        int rightHeight = diameterHelper(root->right,diameter);

        diameter = max(diameter,leftHeight + rightHeight);

        return 1 + max(leftHeight,rightHeight);
    }
    
};