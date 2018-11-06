//
// Created by 许雷 on 2018/11/6.
//

//200.岛屿的个数

// 并查集写法 也可用BFS DFS

class Solution {
public:
    // 并查集数据结构
    vector<int > id;
    void unionG(int m,int n){
        int rootM = find(m);
        int rootN = find(n);

        if(rootM==rootN)
            return;
        id[rootN] = rootM;
    }

    int find(int i){
        while (i!=id[i]){
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row==0)
            return 0;
        int column = grid[0].size();
        int total = row*column;
        set<int> res;

        id = vector<int>(total,0);

        for(int i = 0;i<total;++i){
            id[i] = i; // 初始化id
            int x = i/column;
            int y = i%column;
            int down = x+1;
            int right = y+1;

            // 对每个点将他与他的下面和右边相比较
            if(down<row && grid[x][y]==grid[down][y]){
                unionG(i,i+column);
            }
            if(right<column && grid[x][y]==grid[x][right]){
                unionG(i,i+1);
            }
        }

        for(int i = 0;i<total;++i){
            int x = i/column;
            int y = i%column;
            if(grid[x][y]=='1'){
                res.insert(find(i));
            }
        }
        return res.size();
    }
};
