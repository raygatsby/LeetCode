//
// Created by 许雷 on 2018/12/3.
//

//33.搜索旋转排序数组
class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.size() == 0)
            return -1;

        int l = 0;
        int r = nums.size()-1;


        while (l < r) {

            int mid = (l + r) / 2;

            // 在左半部分
            if(nums[mid] > nums[r]){

                if(target > nums[mid] || target <= nums[r]){
                    l = mid +1;
                }else if(nums[mid] == target){
                    return mid;
                } else{
                    r = mid -1;
                }
            }else{
                // 在右半部分
                if(target > nums[mid] && target <= nums[r]){
                    l = mid +1;
                }else if(nums[mid] == target){
                    return mid;
                } else{
                    r = mid -1;
                }
            }
        }
        return -1;
    }
};