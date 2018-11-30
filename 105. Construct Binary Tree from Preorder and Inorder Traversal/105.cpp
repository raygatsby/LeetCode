//
// Created by 许雷 on 2018/11/30.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//105. 从前序与中序遍历序列构造二叉树

class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& vin) {
        if(pre.size()==0||vin.size()==0){
            return nullptr;
        }
        int a = pre[0];
        TreeNode * root = new TreeNode(a);
        vector<int> pre1;
        vector<int> vin1;
        vector<int> pre2;
        vector<int> vin2;

        int pos = 0;  // a在vin中的位置

        int pre_size = pre.size();
        int vin_size = vin.size();
        for(int i = 0;i<vin_size;i++){
            if (vin[i]==a){
                pos = i;
                break;
            }
        }

        for(int i = 1;i<pre.size();++i){
            if(i<=pos){
                pre1.push_back(pre[i]);
            } else{
                pre2.push_back(pre[i]);
            }
        }

        for (int i = 0; i < vin_size; ++i) {
            if(i<pos){
                vin1.push_back(vin[i]);
            } else if (i>pos){
                vin2.push_back(vin[i]);
            }
        }
        root->left = buildTree(pre1,vin1);
        root->right = buildTree(pre2,vin2);
        return root;
    }
};