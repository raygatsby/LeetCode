//
// Created by 许雷 on 2018/10/8.
//

#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        if(s.length()==0){
            return "";
        }
        int dp[s.length()][s.length()] = {0};


        for(int i = 0;i<s.length();i++){
            dp[i][i] = 1;
        }

        int m = 0,n = 0;
        int Max = 1;

        for(int j = 1;j<s.length();j++){


            for(int i = 0;i<=s.length()-2;i++){

                if(i+j<s.length()){
                    if(s[i]==s[i+j]){

                        if(j>=2&&dp[i+1][i+j-1]!=j-1){
                            dp[i][i+j] = max(dp[i][i+j-1],dp[i+1][i+j]);
                        }else{
                            dp[i][i+j] = dp[i+1][i+j-1] + 2;
                        }


                    }else{
                        dp[i][i+j] = max(dp[i][i+j-1],dp[i+1][i+j]);
                    }

                    if(dp[i][i+j]>Max) {
                        Max = dp[i][i+j];
                        m = i;
                        n = i+j;
                    }
                }
            }
        }
        return s.substr(m,Max);
    }
};


