//
// Created by 许雷 on 2018/11/19.
//

//513.找树左下角的值
// BFS做法
#if 1
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        queue<TreeNode *> q,pre;
        q.push(root);
        while (!q.empty()){
            pre = q;
            size_t q_size = q.size();
            while(q_size--){
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            if(q.empty()){
                return pre.front()->val;
            }
        }
        return pre.front()->val;
    }
};
#endif

