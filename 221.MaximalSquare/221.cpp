//
// Created by 许雷 on 2018/10/23.
//

// 最大正方形
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0){
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int >(n,0));
        int res = 0;
        // 对每个位置 i，j的最大正方形是由3个地方决定的
        // 有 i，j的左边 右边 和 左上方决定
        // 所以ij值 取这3个方向连续的1 的最小值
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                if(matrix[i][j]=='1'){

                    if(i>0&&j>0){
                        // 状态转移方程
                        dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    }else{
                        dp[i][j] = matrix[i][j]=='1'?1:0;
                    }
                    res = max(res,dp[i][j]);
                } else{
                    dp[i][j]=0;
                }
            }
        }
        return res*res;
    }
};
// 这是最开始写的暴力写法 思路都对 就是没有优化好 空间复杂度和时间复杂度都很高 导致超时
// 也算是锻炼了编码能力把  有很多边界值在考虑
#if 0
//17.30
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        if(m==0){
            return 0;
        }
        int n = matrix[0].size();

        int max_edge = min(m,n);

        long long dp[max_edge+1][m+10][n+10];
        int left[max_edge+1][n+10][n+10];
        int top[max_edge+1][m+10][m+10];
        bool have1 = false;

        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                have1 = true;
                dp[1][i][j] = matrix[i][j]=='1'?1:0;
                if(i!=0&&j!=0){
                    left[1][i][j] = matrix[i][j-1]=='1'?1:0;
                    top[1][i][j] = matrix[i-1][j]=='1'?1:0;
                }
            }
        }
        long long res = have1?1:0;

        for(int i = 2;i<=max_edge;++i){

            for(int j = i-1;j<m;++j){
                for(int k = i-1;k<n;++k){

                    int count = 0;
                    if(left[i-1][j][k]==i-1 && matrix[j][k]=='1'){
                        left[i][j][k+1] = i;
                        count++;
                    }
                    if(top[i-1][j][k]==i-1 && matrix[j][k]=='1'){
                        top[i][j+1][k] = i;
                        count++;
                    }
                    if(dp[i-1][j-1][k-1]==(i-1)*(i-1)&&count==2){
                        dp[i][j][k] = i*i;
                    }else{
                        dp[i][j][k] = 0;
                    }
                    res = max(res,dp[i][j][k]);
                }
            }
        }
        return res;
    }
};
#endif