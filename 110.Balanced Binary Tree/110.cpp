//
// Created by 许雷 on 2018/11/14.
//

//110.验证平衡二叉树
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;

        int max_left = 0;
        int max_right = 0;

        travel(root->left,max_left,1);
        travel(root->right,max_right,1);

        if(abs(max_left-max_right)>=2) return false;

        if(isBalanced(root->left) && isBalanced(root->right)) return true;

        return false;
    }

    // 得到子树高度
    void travel(TreeNode *p,int &Max,int level){
        if(!p) return;
        Max = max(Max,level);
        travel(p->left,Max,level+1);
        travel(p->right,Max,level+1);
    }

};