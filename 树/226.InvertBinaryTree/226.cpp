//
// Created by eden on 18-10-26.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 翻转二叉树
// 15.39
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(!root){
            return NULL;
        }

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->left);
        invertTree(root->right);

        return root;

    }
};