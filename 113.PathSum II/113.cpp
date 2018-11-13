//
// Created by eden on 18-11-13.
//
//113.路径总和
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(root,res,tmp,sum);
        return res;
    }

    void dfs(TreeNode *root,vector<vector<int>> &res,vector<int> &tmp,int sum){

        if(!root)
            return;

        // 当递归到叶子结点时 可以根据条件更新res
        if(root->left==NULL && root->right==NULL){
            if(root->val == sum){
                tmp.push_back(root->val);
                res.push_back(tmp);
            }
            return;
        }

        vector<int> l = tmp;
        vector<int> r = tmp;

        //左子树存在 拷贝一个tmp副本往左递归
        if(root->left){
            l.push_back(root->val);
            dfs(root->left,res,l,sum-root->val);
        }
        //右子树存在 拷贝一个tmp副本往右递归
        if(root->right){
            r.push_back(root->val);
            return dfs(root->right,res,r,sum-root->val);

        }
    }
};
