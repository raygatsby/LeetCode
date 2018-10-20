//
// Created by 许雷 on 2018/10/20.
//

// 91.解码方法
class Solution {
public:
    int numDecodings(string s) {

        int size = s.size();
        int dp[size+1];
        long long res = 0;

        for(int i = 0;i<=size;++i){
            dp[i] = 0;
        }
        dp[0] = 0;

        if(s[0]=='0'){
            return 0;
        }
        dp[1] = 1;
        for(int i = 2;i<=size;++i){
            int j = i-1;
            int gewei = s[i-1]-'0';
            int shiwei = s[j-1]-'0';
            int tmp = gewei+10*shiwei;

            // 每个0必须找到与他搭配的 否则直接返回0
            if(gewei==0&&(shiwei==0||shiwei>=3)){
                return 0;
            }
            if (gewei!=0)
                dp[i] = dp[j];
            if(tmp>=10 && tmp <=26){
                if(dp[j-1]!=0){
                    dp[i] += dp[j-1];
                } else{
                    dp[i] +=1;
                }
            }
        }

        return dp[size];
    }
};