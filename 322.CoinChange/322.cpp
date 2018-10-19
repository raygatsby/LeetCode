//
// Created by 许雷 on 2018/10/19.
//

// 322.零钱兑换

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int size = coins.size();
        sort(coins.begin(), coins.end());

        // dp[i][j]表示有前i个硬币 能拼出和为j的最小硬币个数
        int dp[size][amount+1];
        for(int i =0 ;i<size;++i){
            dp[i][0] = 0;
        }

        // 对最小的硬币可以直接初始化
        for(int i = 1;i<=amount;++i){
            dp[0][i] = i%coins[0]==0?i/coins[0]:-1;
        }


        for(int j = 1;j<=amount;++j){

            for(int i = 1;i<size;++i){

                if(coins[i] > j){
                    // 当这个硬币的大小比j还要大时  很显然不能选当前这个coin
                    dp[i][j] = dp[i-1][j];
                } else{
                    // 这个硬币值比j小 则存在选这个硬币的可能
                    if(dp[i][j-coins[i]]!=-1){
                        // 选了当前硬币后剩余的j-coins[i]可以有已有硬币拼出来
                        if(dp[i-1][j]!=-1){
                            // 比较 最小值
                            dp[i][j] = min(dp[i][j-coins[i]]+1,dp[i-1][j]);
                        } else{
                            // 这是没有这个硬币 则不能拼出来 j 所以一定要选这个硬币
                            dp[i][j] = dp[i][j-coins[i]]+1;
                        }

                    } else{
                        // 如果选了当前硬币之后 剩余的j-coins【i】不能由已有硬币拼出来
                        // 所以就不能选当前硬币
                        dp[i][j] = dp[i-1][j];
                    }
                }

            }
        }
        return dp[size-1][amount];
    }
};