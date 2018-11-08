//
// Created by 许雷 on 2018/11/8.
//

//684.冗余连接

// 这题其实很简单
// 一画图模拟一遍就能懂了
class Solution {
public:
    // 并查集数据结构
    vector<int> id;
    int find(int i){
        while (i!=id[i]){
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

    void Unions(int m,int n){
        id[find(n)] = find(m);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        id = vector<int>(n+1,0);
        for (int i=1;i<=n;++i) {
            id[i] = i;
        }
        vector<int> res;

        for(int i = 0;i<n;++i){

            // 如果这两个点在之前已经被间接挂在在一起了
            // 则这个边就会使树变得有环
            if(find(edges[i][1]) == find(edges[i][0])){
                res = edges[i];
                break;
            }else{
                Unions(edges[i][0],edges[i][1]);
            }
        }
        return res;
    }
};