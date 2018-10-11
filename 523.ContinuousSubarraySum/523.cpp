//
// Created by 许雷 on 2018/10/10.
//
//连续子数组和
// 这题跟第139题 单词拆分好像啊 一个类型的

// 做完 139 在做这题 发现可以用这题的解法去写 139
// 可以降低 空间复杂度



#include <vector>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int size = nums.size();
        if(size<=1){
            return false;
        }
        //dp[i]表示前 i 个数的和
        int dp[size+1];
        dp[0] = 0;

        for(int i = 1;i<=size;++i){
            for(int j = i;j>=1;--j){

                //dp[i] 在退出内层循环时 值为变成前i个数的和
                // 在此之前 dp【i】 表示从下标 j 到 i 的数组值的和
                dp[i] = dp[i-1] - dp[j-1] + nums[i-1];

                // 保证 i 不等于 j 才能使 子数组个数大于等于2
                if(k!=0&&dp[i]%k==0&&i!=j){
                    return true;
                } else if(k==0&&dp[i]==0&&j!=i){
                    return true;
                }
            }
        }
        return false;
    }
};