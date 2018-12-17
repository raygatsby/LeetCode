//
// Created by 许雷 on 2018/12/17.
//

//26. Remove Duplicates from Sorted Array
// 26. 删除排序数组中的重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }

        int slow = 0;
        int fast = slow + 1;

        while (slow < nums.size() && fast < nums.size()){

            // slow表示符合条件的序列的最后一个元素的下标
            if(nums[fast] == nums[slow]){
                fast++;
            }else{
                // 找到符合条件的数 就把他和slow+1那个数交换
                swap(nums[slow+1],nums[fast]);
                slow++;
                fast++;
            }
        }
        return slow+1;
    }
};