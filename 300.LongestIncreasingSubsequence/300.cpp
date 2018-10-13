//
// Created by 许雷 on 2018/10/13.
//

// 最大上升子序列
//https://leetcode-cn.com/problems/longest-increasing-subsequence/


#include <vector>
// 17.12 -- 17.20
// 最大上升子序列

#include <iostream>;
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size==0){
            return 0;
        }
        int dp[size];
        for (int i = 0; i < size; ++i) {
            dp[i] = 1;
        }
        int top_max = 1;
        for(int i = 0;i<size;++i){
            // 这里Max初值应该为 1 开始为0导致计算错了
            int Max = 1;
            //下面这个循环可以用二分查找来解决 这样可以把时间复杂度从 O(n^2) 降低为 O(nlog(n));


            for (int j = i-1; j >= 0; --j) {
                if(nums[i] > nums[j]){
                    Max = max(dp[j]+1,Max);
                }
            }
            dp[i] = Max;
            top_max = max(top_max,Max);
        }
        return top_max;
    }
};



