//
// Created by eden on 18-10-24.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//二叉树前序遍历

// 递归写法
#if 0
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {

        if(root){
            res.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return res;
    }
};
#endif

// 非递归写法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        stack<TreeNode *> help;


        // 跟中序遍历差不多的循环
        while (root || !help.empty()){

            // 往左走的过程中就记录值
            while (root){
                res.push_back(root->val);
                help.push(root);
                root = root->left;
            }

            if(!help.empty()){
                root = help.top();
                root = root->right;
                help.pop();
            }
        }
        return res;
    }
};