//
// Created by eden on 18-10-18.
//


// 486.预测赢家
class Solution {
public:


    bool PredictTheWinner(vector<int>& nums) {

        int size = nums.size();
        if(size == 1 ){
            return true;
        }
        int dp[size][size];
        int sum[size][size];
        // dp[i][j] 在ij先选的玩家能获得的最大分数
        // sum[i][j] ij的总分数
        for(int i = 0;i<size;++i){
            dp[i][i] = nums[i];
            sum[i][i] = nums[i];
        }

        for(int l=2;l<=size;++l){
            for(int i = 0;i<size-l+1;++i){
                int j = i+l-1;
                sum[i][j] = sum[i][j-1] + nums[j];
                // 每次不是选i就是选j
                // 所以很容易写出状态转换方程
                dp[i][j] = max(nums[j]+sum[i][j-1]-dp[i][j-1],nums[i]+sum[i+1][j]-dp[i+1][j]);
            }

        }

        int tmp = sum[0][size-1] - dp[0][size-1];
        return dp[0][size-1] >= tmp;
    }

};