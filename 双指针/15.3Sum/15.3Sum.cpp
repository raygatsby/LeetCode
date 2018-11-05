//
// Created by 许雷 on 2018/10/16.
//

// 3sum
// https://leetcode-cn.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {

        int size = nums.size();
        if(size<=2){
            return res;
        }
        // 先排序
        sort(nums.begin(),nums.end());

        for(int i = 0;i<size-2;++i){

            // 对于 nums[i] 在下面while循环里就找出含有这个 nums[i] 的全部值
            // 所以再遇到 nums[i] 可以直接跳过 不进入循环
            if(i==0 || nums[i] != nums[i-1] ){
                int key = 0-nums[i];

                int j = i+1;
                int k = size-1;

                // nums[j] < nums[k]
                // j到k是一个单调不减数列
                // 所以 如果 nums[j] + nums[k] > key 则应该改变 k的值
                // 反之亦然
                while (j<k){
                    if(nums[j]+nums[k] > key){

                        while (j<k && nums[k-1] == nums[k]){
                            // 这个循环把所有与 nums[k] 相等的值全部跳过
                            k--;
                        }
                        k--;
                    } else if(nums[j] + nums[k] <key){
                        while (j<k && nums[j+1] == nums[j]){
                            // 这个循环把所有与 nums[j] 相等的值全部跳过
                            j++;
                        }
                        j++;
                    } else{
                        // 找到符合条件的 j，k
                        res.push_back({nums[i],nums[j],nums[k]});
                        while (j<k && nums[k-1] == nums[k]){
                            k--;
                        }
                        while (j<k && nums[j+1] == nums[j]){
                            j++;
                        }
                        k--;
                        j++;
                    }
                }
            }
        }
        return res;
    }
};