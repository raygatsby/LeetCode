//
// Created by 许雷 on 2018/11/30.
//

//岛屿的最大面积

//

//9.07
class Solution {
public:

    // 并查集数据结构
    vector<int > id;
    void Union(int m,int n){
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

    // 用并查集处理数组后很容易得到答案
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int row = grid.size();
        if(row==0)return 0;
        int column = grid[0].size();
        int total = row * column;
        int res = 0;

        unordered_map<int,int> m;

        id = vector<int>(total,0);

        for(int i = 0;i<total;++i){
            id[i] = i;
        }

        for(int i = 0;i<total;i++){

            int x = i/column;
            int y = i%column;

            int right = y+1;
            int down = x+1;

            if(right < column && grid[x][y]==1 && grid[x][right]==1){
                Union(i,i+1);
            }

            if(down < row && grid[x][y]==1 && grid[down][y]==1){
                Union(i,i+column);
            }
        }

        for(int i = 0;i<total;i++){

            int x = i/column;
            int y = i%column;

            if(grid[x][y]==1){
                if(m.count(find(i))==0){
                    m[find(i)] = 1;
                }else{
                    m[find(i)]++;
                }
                cout << find(i) << " ";
                res = max(res,m[find(i)]);
            }
        }
        return res;
    }
};
