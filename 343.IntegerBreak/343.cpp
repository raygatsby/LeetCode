//
// Created by 许雷 on 2018/10/20.
//

// 343.整数拆分
class Solution {
public:
    int integerBreak(int n) {

        int dp[n+1];
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3;i<=n;++i){
            int Max = INT_MIN;
            for(int j = 1;j<i;++j){
                // 用dp存储每个数的最优值
                // 所以可以直接只把i分解成两个数
                Max = max(Max,max(dp[i-j],i-j)*j);
            }
            dp[i] = Max;
        }
        return dp[n];
    }
};