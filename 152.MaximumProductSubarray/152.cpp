//
// Created by 许雷 on 2018/10/17.
//

// 乘积最大子数组
// 15.05
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();

        int maxPre = nums[0];
        int minPre = nums[0];
        int res = nums[0];

        for(int i =1;i!=size;++i){

            // maxpre表示前面与i相连的乘积中能提供给 nums[i] 的最大的数
            // minpre表示前面与i相连的乘积中能提供给 nums[i] 的最小的数

            int tmp1 = maxPre*nums[i];
            int tmp2 = minPre*nums[i];

            maxPre = max(max(tmp1,tmp2),nums[i]);
            minPre = min(min(tmp1,tmp2),nums[i]);

            res = max(maxPre,res);

        }
        return res;

    }
};