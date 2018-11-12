//
// Created by 许雷 on 2018/11/12.
//

// 934.最短的桥
// DFS+BFS
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A){
        queue<pair<int,int>> q; // 存储找到的岛的坐标和往外寻找时的经过的坐标
        bool found = false;
        ssize_t size = A.size();

        for(int i=0;i<size;++i){  // 找到一个岛
            for(int j=0;j<size && !found;++j) {
                if(A[i][j]==1){
                    dfs(A, q, i, j);
                    found = true;
                }
            }
        }

        vector<int> dirs{0,-1,0,1,0};  // 控制上下左右

        int res = 0;

        while (!q.empty()){  // 广度优先搜索
            ssize_t q_size = q.size();
            while (q_size-->0){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;++i){
                    int tx = x+dirs[i];
                    int ty = y+dirs[i+1];   // tx ty 是当前节点的周围四个节点坐标
                    if(tx<0 || tx>=size || ty<0 || ty>=size || A[tx][ty]==2) continue;  // 不符合条件跳过
                    if(A[tx][ty]==1) return res;   // 通过广搜找到另一个岛 就退出
                    A[tx][ty] = 2;
                    q.emplace(tx,ty);
                }
            }
            ++res;
        }
        return -1;
    }

    // 深度优先搜索
    void dfs(vector<vector<int>> &A,queue<pair<int,int>> &q,int x,int y){
        if(x<0 || x>=A.size() || y<0 || y>=A.size() || A[x][y]!=1) return;
        A[x][y] = 2;
        q.emplace(x,y);
        dfs(A,q,x-1,y);
        dfs(A,q,x+1,y);
        dfs(A,q,x,y-1);
        dfs(A,q,x,y+1);
    }

};