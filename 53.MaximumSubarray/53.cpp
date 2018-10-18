//
// Created by eden on 18-10-18.
//

// 最大子序和
// 做做简单题找点自信。。。。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int size = nums.size();

        int Max = nums[0];

        int res= nums[0];
        for(int i = 1;i<size;++i){
            Max = max(Max+nums[i],nums[i]);
            res = max(res,Max);
        }
        return res;

    }
};