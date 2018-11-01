//
// Created by 许雷 on 2018/10/29.
//

// 650.只有两个键的键盘
// 12.51

class Solution {
public:
    int minSteps(int n) {

        // dp[i] 等于答案
        int dp[1000+1];

        dp[0] = 0;
        for(int i = 1;i<=n;++i){
            if(i%2==0){
                dp[i] = min(dp[i/2]+2,i);
            }else{
                dp[i] = min(dp[(i-1)/2]+2,i);
            }
        }
        return dp[n];
    }
};