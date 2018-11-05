//
// Created by 许雷 on 2018/11/4.
//

//14.31
//287.寻找重复数

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        // 排序后直接与前一个数比较
        sort(nums.begin(),nums.end());
        for(int i = 1;i<size;++i){

            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
    }
};


//static const auto init = []() {
//
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    return nullptr;
//
//}();

// 最优的方法
// 设置快慢指针
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};
