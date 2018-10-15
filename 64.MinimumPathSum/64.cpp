//
// Created by eden on 18-10-14.
//

// 最小路径和
// https://leetcode-cn.com/problems/minimum-path-sum/

// 动态规划

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();

        if(m==0){
            return 0;
        }

        int n = grid[0].size();

        int dp[m][n];
        dp[0][0] = grid[0][0];

        // 对边界直接进行初始化
        // 因为边界只有一种走法
        for(int i = 1;i<n;i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        for(int i = 1;i<m;++i){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }


        for(int i = 1;i<m;++i){
            for(int j = 1;j<n;j++){
                //这里决定走到i，j时是怎么走下来的 从i-1,i 和i,j-1 里选一个走
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
