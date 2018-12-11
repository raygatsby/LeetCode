//
// Created by 许雷 on 2018/12/11.
//

//35.搜索插入位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        if(nums.size()==0)
            return 0;

        int l = 0;
        int r = nums.size()-1;
        int mid = (l+r)/2;
        while (l <= r){

            mid = (l+r)/2;

            if(target < nums[mid]){
                r = mid-1;
            }else if(target > nums[mid]){
                l = mid+1;
            }else{
                return mid;
            }
        }
        if(target > nums[mid]){
            return mid+1;
        }else{
            return mid;
        }
    }
};