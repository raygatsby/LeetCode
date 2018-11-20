//
// Created by eden on 18-11-20.
//

//103. 二叉树的锯齿形层次遍历
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;
        if(!root)
            return res;
        deque<TreeNode *> d;
        d.push_back(root);
        int count = 1;  // 用count来表示到达的层数是奇数层还是偶数层 从而表明是正序输出还是逆序输出

        while (!d.empty()){

            size_t n = d.size();
            vector<int> row;
            while (n-->0){

                if(count%2==0 ){
                    TreeNode *tmp = d.front();
                    d.pop_front();
                    row.push_back(tmp->val);
                    if(tmp->right)
                        d.push_back(tmp->right);
                    if(tmp->left)
                        d.push_back(tmp->left);
                }else{
                    TreeNode *tmp = d.back();
                    d.pop_back();
                    row.push_back(tmp->val);
                    if(tmp->left)
                        d.push_front(tmp->left);
                    if(tmp->right)
                        d.push_front(tmp->right);
                }

            }
            res.push_back(row);
            ++count;
        }
        return res;
    }
};