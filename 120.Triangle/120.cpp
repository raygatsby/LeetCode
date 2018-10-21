//
// Created by eden on 18-10-21.
//

//120.三角形最小路径和
//14.44
//数塔问题
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int size = triangle.size();
        // 自底向上计算
        for(int i = size-2;i>=0;--i){
            int two_size = triangle[i].size();
            for(int j = 0;j<two_size;++j){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];

    }
};