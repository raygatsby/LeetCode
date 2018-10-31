//
// Created by eden on 18-10-31.
//



//650
//15.50
class Solution {
public:
    int minSteps(int n) {

        int dp[1000+1];

        dp[1] = 0;
        dp[2] = 2;
        for(int i = 3;i<=n;++i){
            dp[i] = i;
            for(int j = i/2;j>=2;--j){
                // 每次都应该选择最多的字符进行复制
                if(i%j==0){
                    dp[i] = min(dp[i],dp[j] + i/j);
                    break;
                }
            }

        }
        return dp[n];
    }
};