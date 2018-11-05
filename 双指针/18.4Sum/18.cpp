//
// Created by 许雷 on 2018/11/4.
//


// 18.4Sum
// 本题与 15 16 是一种类型
// 用双指针解决

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> res;
        if(size<4)
            return res;

        sort(nums.begin(),nums.end());

        for(int i = 0;i<size;++i){
            // 去重
            if(i==0 || nums[i]!=nums[i-1]){
                for(int j = i+1;j<size;++j){
                    // 去重
                    if(j==i+1 || nums[j]!=nums[j-1]){

                        int key = target-nums[i]-nums[j];
                        int left = j+1;
                        int right = size-1;
                        while (left<right){

                            if(nums[left]+nums[right] < key){
                                // 去重
                                while (left<right && nums[left+1]==nums[left]){
                                    left++;
                                }
                                left++;
                            }else if(nums[left]+nums[right] > key){
                                // 去重
                                while (left<right && nums[right-1]==nums[right]){
                                    right--;
                                }
                                right--;
                            } else{
                                // 符合条件的值
                                res.push_back({nums[i],nums[j],nums[left],nums[right]});
                                // 去重
                                while (left<right && nums[left+1]==nums[left]){
                                    left++;
                                }
                                left++;
                                // 去重
                                while (left<right && nums[right-1]==nums[right]){
                                    right--;
                                }
                                right--;
                            }

                        }
                    }
                }

            }

        }
        return res;
    }
};