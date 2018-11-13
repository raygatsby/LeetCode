//
// Created by eden on 18-11-13.
//

// 112.路径总和
#if 0
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {

        if(!root)
            return false;

        if(root->left==NULL && root->right==NULL)
            return sum==root->val;

        if(root->left){
            if(hasPathSum(root->left,sum-root->val)) {
                return true;
            } else{
                if(root->right){
                    return hasPathSum(root->right,sum-root->val);
                }
            }
        } else{
            if(root->right){
                return hasPathSum(root->right,sum-root->val);
            }
        }
        return false;
    }
};
#endif