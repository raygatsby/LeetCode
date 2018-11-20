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


//11.19号重写 还没忘
//152.乘积最大子序列
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        size_t size = nums.size();
        if(size == 0)
            return 0;
        int Min,Max,res;
        res = Min = Max = nums[0];
        for(int i=1;i<size;++i){
            int tmp_max = Max;
            int tmp_min = Min;

            // Max Min 是给下一个能够提供的最大值和最小值  所以在Max和Min的赋值语句中必须有nums[i]存在 才能与下一个nums[i+1]连在一起
            Max = max(max(tmp_max*nums[i],tmp_min*nums[i]),nums[i]);
            Min = min(min(tmp_max*nums[i],tmp_min*nums[i]),nums[i]);
            res = max(res,Max);   // 在循环过程中保存最大值
        }
        return res;
    }
};