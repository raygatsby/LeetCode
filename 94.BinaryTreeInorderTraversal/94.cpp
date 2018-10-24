//
// Created by eden on 18-10-24.
//

// 94.二叉树的中序遍历
// 19.08

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归写法
#if 0
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
};
#endif

// 非递归写法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;

        stack<TreeNode *> help;

        while (root || !help.empty()){

            // 一直往左走
            while (root){
                help.push(root);
                root = root->left;
            }

            if (!help.empty()){
                root = help.top();
                res.push_back(root->val);
                help.pop();
                root = root->right;
            }
        }
        return res;
    }
};