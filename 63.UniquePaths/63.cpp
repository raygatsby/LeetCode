//
// Created by 许雷 on 2018/10/10.
//


//经典动态规划
//这是第63题
//https://leetcode-cn.com/problems/unique-paths/

#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {

        if(m==1&&n==1){
            return 1;
        }

        int dp[m][n]; // 从坐标 （0，0） 走到 坐标 （m-1，n-1）

        //首先 把边界进行初始化
        for(int i = 1;i<m;i++){
            dp[i][0] = dp[0][i] = 1;
        }

        for(int i = 1;i<m;++i){
            for(int j = 1;j<n;++j){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
