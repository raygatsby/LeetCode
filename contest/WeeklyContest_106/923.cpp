//
// Created by eden on 18-10-14.
//

// 923.三数之和的多种可能
// https://leetcode-cn.com/problems/3sum-with-multiplicity/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int dp[3][305];

    int threeSumMulti(vector<int>& A, int target)
    {

        const int mod = 1e9 + 7;
        int len = (int)A.size();
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < len; i++) {
            for (int j = 2; j >= 1; j--)  // j==1 表示用2个数拼 target
                for (int k = target; k >= A[i]; k--)

                {           // dp[j][k] 表示用 j-1 个数来拼出 target
                    dp[j][k] = (dp[j][k] + dp[j - 1][k - A[i]]) % mod;  // 所以可以得到这个状态转移方程
                    cout << "j:" << j << "k: " << k << "$$$" << dp[j][k] <<  endl;
                }

            dp[0][A[i]] = (dp[0][A[i]] + 1) % mod;   // 实际上就是j==0的情况 即只用一个数来组成target
            cout << A[i] << "&&" << endl;

        }
        return dp[2][target];
    }
};