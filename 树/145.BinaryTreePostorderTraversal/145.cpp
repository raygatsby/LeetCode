//
// Created by eden on 18-10-24.
//

// 后序遍历非递归是最难的 在3种遍历方式里面

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 二叉树后序遍历
// 递归算法

#if 0
class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {

        if(root){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            res.push_back(root->val);
        }
        return res;
    }
};
#endif

// 非递归算法
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode *> help;

        TreeNode *cur;         // 当前正在访问的结点
        TreeNode *pre = NULL; // 记录root的前一个结点

        help.push(root);

        while (!help.empty()){

            cur = help.top();
            // 如果当前结点没有孩子 则可以直接访问
            // 如果当前结点的上一个访问结点是他孩子 也可以直接访问
            if((cur->left==NULL && cur->right==NULL ) || (pre && (pre==cur->left || pre==cur->right))){
                res.push_back(cur->val);
                help.pop();
                pre = cur;
            }else{

                // 先把右孩子入栈再把左孩子入栈
                // 这样出栈时就先访问左孩子
                if(cur->right){
                    help.push(cur->right);
                }
                if(cur->left){
                    help.push(cur->left);
                }

            }
        }
        return res;
    }
};