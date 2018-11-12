//
// Created by 许雷 on 2018/11/12.
//

//542.01矩阵
// BFS解决
class Solution {
public:
    const vector<int> dirs{0,-1,0,1,0};

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        ssize_t row = matrix.size();
        if(row==0) return res;
        ssize_t column = matrix[0].size();

        res = vector<vector<int>> (row,vector<int>(column,0));

        for(int i = 0;i<row;++i){
            for(int j=0;j<column;++j){
                if(matrix[i][j]==0)
                    res[i][j] = 0;
                else
                    res[i][j] = bfs(i,j,matrix);
            }
        }
        return res;
    }

    // 广度优先搜索
    int bfs(int x,int y,vector<vector<int>> &matrix){
        queue<pair<int,int>> q;
        set<pair<int,int>> set1;  // 如果一个点的邻居都被访问过了  就把这个点放入set1里面
        q.emplace(x,y);
        int steps = 1;
        while (!q.empty()){
            ssize_t size = q.size();
            while (size--){
                int i = q.front().first;
                int j = q.front().second;
                set1.emplace(i,j);   //接下来访问i，j的邻居 所以ij放入set1
                q.pop();
                for(int m=0;m<4;++m){
                    int ti = i+dirs[m];
                    int tj = j+dirs[m+1];
                    // 邻居不合条件 直接continue
                    if(ti<0 || ti>=matrix.size() || tj<0 || tj>=matrix[0].size() || set1.count({ti,tj})==1) continue;
                    if(matrix[ti][tj]==0) return steps; // 找到0  返回steps
                    q.emplace(ti,tj);
                }
            }
            ++steps;
        }
    }
};