//
// Created by eden on 18-10-27.
//


// 104.二叉树的最大深度
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int res = 0;

    int maxDepth(TreeNode* root) {
        travel(root,1);
        return res;

    }

    void travel(TreeNode *root,int k){
        if(root){
            travel(root->left,k+1);
            travel(root->right,k+1);
            res = max(k,res);
        }
    }
};