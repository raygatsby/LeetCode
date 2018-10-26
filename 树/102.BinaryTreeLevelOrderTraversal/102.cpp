//
// Created by eden on 18-10-25.
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

//二叉树从上往下层次遍历

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 14.30
// 二叉树从上往下层次遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int >> res;

        if(!root){
            return res;
        }
        deque<TreeNode *> help;

        // 在每一层的后面都加一个标志性的NULL指针
        help.push_back(root);
        help.push_back(NULL);


        while (help.size()>1){

            vector<int > temp;

            // 用加进去的NULL指针来表示这一层是否迭代完了
            while (help.front()!=NULL){
                TreeNode* tmp = help.front();
                temp.push_back(tmp->val);
                if(tmp->left){
                    help.push_back(tmp->left);
                }
                if(tmp->right){
                    help.push_back(tmp->right);
                }
                help.pop_front();
            }
            help.pop_front();
            help.push_back(NULL);
            res.push_back(temp);
        }
        return res;
    }
};