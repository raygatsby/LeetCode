//
// Created by 许雷 on 2018/10/13.
//

// 不同路径2
// https://leetcode-cn.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        if(m==0){
            return 0;
        }
        int n = obstacleGrid[0].size();

        int dp[m][n]; // 从坐标 （0，0） 走到 坐标 （m-1，n-1）
        int pos = m;
        //首先 把边界进行初始化
        // 找到竖直方向的第一个阻塞点
        // 用pos记录
        for(int i = 0;i<m;i++){
            if(obstacleGrid[i][0]==1){
                dp[i][0] = 0;
                pos = i;
                break;
            }
            dp[i][0] = 1;
        }
        // pos后面的格子不能到达所以全为0
        for(int i = pos+1;i<m;++i){
            dp[i][0] = 0;
        }

        // 水平方向类似竖直方向
        pos = n;
        for(int i = 0;i<n;i++){
            if(obstacleGrid[0][i]==1){
                dp[0][i] = 0;
                pos = i;
                break;
            }
            dp[0][i] = 1;
        }
        for(int i = pos+1;i<n;++i){
            dp[0][i] = 0;
        }// 初始化完成

        for(int i = 1;i<m;++i){
            for(int j = 1;j<n;++j){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};