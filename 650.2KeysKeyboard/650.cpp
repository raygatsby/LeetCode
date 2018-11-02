//
// Created by 许雷 on 2018/10/29.
//

// 650.只有两个键的键盘
// 12.51

class Solution {
public:
    int minSteps(int n) {

        int dp[1000+1];

        dp[1] = 0;
        dp[2] = 2;
        for(int i = 3;i<=n;++i){
            dp[i] = i;
            for(int j = i/2;j>=2;--j){
                if(i%j==0){
                    dp[i] = min(dp[i],dp[j] + i/j);
                    break;
                }
            }

        }
        return dp[n];
    }
};