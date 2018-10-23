//
// Created by 许雷 on 2018/10/23.
//

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        int dp[10001];
        int sum[10001] = {0};

        int size = nums.size();

        for(int i = 0;i<size;++i){
            // 每个数的所有重复值加起来
            // 比如 2 2 3 3 3 4 这个歌数组
            // 则 num[2] = 4
            sum[nums[i]] += nums[i];
        }

        dp[0] = 0;
        dp[1] = sum[1];
        for(int i=2;i<=10000;++i){
            // 对每个数 选着他之后就不能选他的前一个数
            // 所以有一个状态转移方程
            // 取最大值
            dp[i] = max(dp[i-1],dp[i-2]+sum[i]);
        }

        return dp[10000];


    }
};