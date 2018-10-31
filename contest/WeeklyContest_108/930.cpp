//
// Created by eden on 18-10-31.
//

//930.和相同的二元子数组

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {

        int size = A.size();

        vector<int> sum(size+1);
        sum[0] = 0;

        int f[30003] = {0};

        // 因为该数组只有01 所以得到的sum数组必然是一个单调不减数组
        for(int i = 1;i<=size;++i){
            sum[i] = sum[i-1]+A[i-1];
        }
        int ret = 0;


        for(int i = 0;i<=size;++i){

            if(sum[i]-S>=0){
                ret += f[sum[i]-S];
            }
            // 统计每个和出现的次数
            f[sum[i]]++;
        }
        return ret;

    }
};