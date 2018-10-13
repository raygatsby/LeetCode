//
// Created by 许雷 on 2018/10/13.
//

// 最长回文子序列 经典动态规划
// https://leetcode-cn.com/problems/longest-palindromic-subsequence/

#include <string>
#include <algorithm>

using namespace std;

// 19.57
// 最长回文子序列
class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int size = s.size();
        if(size==0) return 0;

        // dp[i][j] 表示从 i到j 的子串的最大回文子序列的长度
        int dp[size][size];
        for(int i = 0;i<size;++i){
            for(int j = 0;j<size;++j){
                dp[i][j] = 0;
            }
            // 对角线初始化为 1
            dp[i][i] = 1;
        }

        for(int l = 2;l<=size;++l){
            for(int i = 0;i<size-l+1;++i){
                int j = i+l-1;

                // 如果 s[i]==s[j] 那么就可以用dp[i+1][j-1]+2的值来算dp[i][j]
                if(s[i]==s[j]){
                    if(i+1>j-1){
                        // 特殊情况 i 和 j 挨着的
                        dp[i][j] = 2;
                    }
                    else
                        dp[i][j] = dp[i+1][j-1]+2;
                } else{
                    // s[i]！=s[j] 则 有：
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][size-1];
    }
};