//
// Created by eden on 18-10-21.
//

// https://leetcode-cn.com/problems/flip-string-to-monotone-increasing/

class Solution {
public:
    int minFlipsMonoIncr(string S) {

        int size = S.size();

        // 因为只有01所以可以找出一个分界点
        // 分界点有size+2种可能
        int dp[size+2];

        int num_0 = 0;
        int num_1 = 0;
        for(int i = 0;i<size;i++){
            if(S[i]=='0'){
                num_0++;
            } else{
                num_1++;
            }
        }
        //分界点在2端的极端情况
        dp[0] = dp[size+1] = min(num_0,num_1);
        int res = dp[0];
        res = min(res,dp[size+1]);


        for(int i = 1;i<=size;++i){

            // 以i为分界点
            // dp[i]就是炫耀移动的次数
            int left_1 = 0;
            int right_0 = 0;
            for(int j = 0;j<i-1;++j){

                if(S[j]=='1')
                    left_1++;
            }

            right_0 = size-i+1-(num_1-left_1);

            dp[i] = left_1+right_0;
            res = min(res,dp[i]);
        }

        return res;


    }
};