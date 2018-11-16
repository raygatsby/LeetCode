//
// Created by 许雷 on 2018/11/16.
//

//863.二叉树中所有距离为 K 的结点
//本题是将每个结点的父节点用一个map存起来 由此将树变成了图 就可以用bfs直接搜索得到结果
class Solution {
public:

    unordered_map<TreeNode *,TreeNode *> parent;  // 存储每个结点的父节点
    unordered_set<TreeNode *> visit;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        set<int> res;
        vector<int> ok;
        queue<TreeNode *> q;
        findParent(root,root);
        q.push(target);
        // BFS搜索
        while (!q.empty()){
            size_t q_size = q.size();
            while (q_size--){
                TreeNode *tmp = q.front();
                q.pop();
                if(visit.count(tmp) != 0)               continue;            // 该节点已经访问过
                if(K==0)                                res.insert(tmp->val);  // BFS走了K步后 满足要求往set里插入
                // 向他的孩子节点和父节点进行搜索
                if(tmp->left)                           q.push(tmp->left);
                if(tmp->right)                          q.push(tmp->right);
                if(parent.find(tmp) != parent.end())    q.push(parent[tmp]);
                visit.insert(tmp);   // 标记 tmp 为已搜索
            }
            if(K==0)  break;
            K--;
        }
        for(int i : res)
            ok.push_back(i);
        return ok;
    }

    // 为每个结点找到她们的父节点 存在map里
    void findParent(TreeNode *par,TreeNode *cur){
        if(par){
            parent[cur] = par;
            if(cur->left)
                findParent(cur,cur->left);
            if(cur->right)
                findParent(cur,cur->right);
        }
    }
};