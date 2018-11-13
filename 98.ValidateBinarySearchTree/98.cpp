//
// Created by eden on 18-11-13.
//

//98.验证二叉搜索树
#if 0
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        if(!root)
            return true;

        if(root->left==NULL && root->right==NULL)
            return true;

        int maxleft = INT_MIN;
        int minright = INT_MAX;

        max_left(root->left,maxleft);
        min_right(root->right,minright);

        // 对当前结点满足如果不满足条件就返回false
        if(root->left){
            if(root->val <= maxleft)
                return false;
        }
        if(root->right){
            if(root->val >= minright)
                return false;
        }
        // 当前结点满足条件后 再判断当前结点的子结点
        if(isValidBST(root->left) && isValidBST(root->right))
            return true;

        return false;
    }

    // 找出左子树的最大值
    void max_left(TreeNode *p,int &maxleft){

        if(!p)
            return;
        maxleft = max(maxleft,p->val);
        max_left(p->left,maxleft);
        max_left(p->right,maxleft);
    }

    //找出右子树的最小值
    void min_right(TreeNode *p,int &minright){

        if(!p)return;
        minright = min(minright,p->val);
        min_right(p->left,minright);
        min_right(p->right,minright);
    }

};
#endif

// 4ms解法
class Solution {
public:
    Solution() : prev(nullptr) {}
    bool isValidBST(TreeNode* p) {
        if (p == nullptr)           return true;
        if (!isValidBST(p->left))   return false;
        if (prev && prev->val >= p->val) return false;
        prev = p;
        return isValidBST(p->right);
    }

private:
    TreeNode* prev;
};