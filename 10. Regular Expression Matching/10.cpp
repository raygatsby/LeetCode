//
// Created by eden on 18-11-21.
//

//10.正则式表达式匹配
class Solution {
public:
    bool isMatch(string s, string p) {

        size_t slen = s.length();
        size_t plen = p.length();

        bool dp[slen+1][plen+1];

//        bool **dp = new bool* [slen+1];
//        for(int i=0;i<=slen;i++){
//            dp[i] = new bool[plen+1];
//        }

        dp[0][0] = true;

        // 初始化当模式串p为空的时候
        for(int i=1;i<=slen;i++){
            dp[i][0] = false;
        }

        // 初始化当字符串s为空的时候
        for(int i=1;i<=plen;i++){
            dp[0][i] = p[i-1]=='*' ? dp[0][i-2] : false;
        }

        for(int i=1;i<=slen;i++){
            for(int j=1;j<=plen;j++){
                // 注释见图片

                if(p[j-1] == '*')
                    dp[i][j] = (dp[i][j-2]) || ((p[j-2]=='.' || p[j-2]==s[i-1]) && dp[i-1][j]);
                else if(p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = s[i-1]==p[j-1] && dp[i-1][j-1];
            }
        }
        return dp[slen][plen];
    }
};