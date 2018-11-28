//
// Created by 许雷 on 2018/11/28.
//

//13.05
//236.二叉树的最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode *> p1;
        vector<TreeNode *> q1;
        vector<TreeNode *> vp;
        vector<TreeNode *> vq;
        dfs(vp,root,p,p1);
        dfs(vq,root,q,q1);
        TreeNode *res = nullptr;
        for(int i=0;i<min(vp.size(),vq.size());i++){
// 得到路径后便很轻易得到最近公共祖先
            if(vp[i] == vq[i]){
                res = vp[i];
            }
            else
                break;
        }
        return res;
    }

    // 找出从根节点到这个个结点的路径
    // 这段代码在的树的题目中用的挺多
    void dfs(vector<TreeNode *> &res,TreeNode *tmp,TreeNode *target,vector<TreeNode *> &parents){

        if(!tmp) return;

        parents.push_back(tmp);

        if(tmp == target){
            res = parents;
            return;
        }
//        vector<TreeNode *> l = parents;
//        vector<TreeNode *> r = parents;

        dfs(res,tmp->left,target,parents);
        dfs(res,tmp->right,target,parents);
        parents.pop_back();
    }
};