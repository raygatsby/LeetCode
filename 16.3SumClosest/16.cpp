//
// Created by 许雷 on 2018/11/1.
//

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int size = nums.size();
        int closest = INT_MAX;
        if(size<3){
            return 0;
        }
        sort(nums.begin(),nums.end());

        for(int i = 0;i<size-1;++i){

            // 对于 nums[i] 在下面while循环里就找出含有这个 nums[i] 的全部值
            // 所以再遇到 nums[i] 可以直接跳过 不进入循环
            if(i==0 || nums[i] != nums[i-1] ){
                int key = target-nums[i];

                int j = i+1;
                int k = size-1;

                // nums[j] < nums[k]
                // j到k是一个单调不减数列
                // 所以 如果 nums[j] + nums[k] > key 则应该改变 k的值
                // 反之亦然
                while (j<k){

                    // 差距
                    int delta = target -( nums[i]+nums[j]+nums[k]);

                    if(delta==0){
                        return target;
                    }

                    if(abs(closest)>abs(delta)){
                        // 更新差距
                        closest = delta;
                    }

                    if(delta>0)
                        j++;
                    else
                        k--;
                }
            }
        }
        return target-closest;
    }
};