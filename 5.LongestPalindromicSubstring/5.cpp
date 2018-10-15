//
// Created by 许雷 on 2018/10/8.
//

#include <string>
using namespace std;

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(size<=1){
            return s;
        }
        // dp[i][j] 表示从下标 i到j 的最小回文子串
        int dp[size][size];
        memset(dp,0, sizeof(int)*size*size);
        // 对角线置为1
        for(int i = 0;i<size;++i){
            dp[i][i] = 1;
        }
        int res_start;
        int res_len;
        int Max = 0;
        for (int l = 2; l <= size; ++l) {
            for(int i =0;i<size-l+1;++i ){
                int j = i+l-1;
                // i,j可以覆盖矩形的右上部分

                if(s[i]==s[j]){
                    if(i+1==j){
                        // 当 i，j正好挨着
                        dp[i][j] = 2;
                    } else{
                        if(dp[i+1][j-1]==j-i-1){
                            // i+1 ---> j-1是一个回文串
                            dp[i][j] = dp[i+1][j-1]+2;
                        } else{
                            // 否则 看去掉 i，j中的哪一个字符
                            dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                        }
                    }
                } else{
                    // i,不等于j直接取两种情况的最大值
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }

                if(dp[i][j] > Max){
                    Max = dp[i][j];
                    res_start = i;
                }
            }
        }
        return s.substr(res_start,Max);
    }
};


