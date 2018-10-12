//
// Created by 许雷 on 2018/10/12.
//

// 最长递增子序列的个数
// https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/

#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size==0){
            return 0;
        }

        // dp[i] 存放 i 的最长递增子序列值
        int dp[size];

        // 这个存放对应的可以从几个数来得到他的dp
        int jige[size];

        for(int i =  0;i<size;++i){
            dp[i] = 1;
            jige[i] = 1;
        }

        int top_max = 0;
        for(int i = 0;i<size;++i){
            int Max = dp[i];
            for(int j = i-1;j>=0;--j)
                if(nums[i] > nums[j])
                    Max = max(Max,dp[j]+1);
            dp[i] = Max;
            // 用tmp 去记录可以从几个数来得到这个值 所以初值为0
            int tmp = 0;
            for(int j = i-1;j>=0;--j){
                if((dp[j]==dp[i]-1)&&(nums[i] > nums[j])){
                    // 当一个数的 dp 值比本数恰好小一 并且 nums[i] > nums[j]
                    // 说明 可以从 j 得到 i
                    // tmp就可以加上 jike【j】
                    tmp += jige[j];
                }
            }

            // 如果tmp==0 说明不能从任何数得到本数  所以jike【i】 就还是他的初值
            if(tmp!=0){
                // tmp!=0 时才通过tmp 改变jige【i】
                jige[i] = tmp;
            }
            top_max = max(top_max,Max);
        }
        int res = 0;
        for(int i = 0;i<size;++i){
            if(dp[i]==top_max){
                res += jige[i];
            }
        }
        return res;
    }
};