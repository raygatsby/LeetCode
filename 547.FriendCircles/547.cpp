//
// Created by 许雷 on 2018/11/6.
//

//547.朋友圈
// 并查集做的  也可以用DFS BFS

class Solution {
public:
    // 并查集数据结构
    vector<int> id;
    void unionM(int m,int n){
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

    int findCircleNum(vector<vector<int>>& M) {

        // 只需用到矩阵的右上部分
        int nums = M.size();

        id = vector<int>(nums,0);
        for(int i = 0;i<nums;++i){
            id[i] = i;
        }

        for(int i = 0;i<nums;++i){
            for(int j = i+1;j<nums;++j){
                if(M[i][j]==1){
                    unionM(i,j);
                }
            }
        }

        set<int> res;
        for(int i = 0;i<nums;++i){
            res.insert(find(i));
        }
        return res.size();
    }
};
