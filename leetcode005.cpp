//
// Created by 许雷 on 2018/10/8.
//

//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。
//
//示例 1：
//
//输入: "babad"
//输出: "bab"
//注意: "aba"也是一个有效答案。
//示例 2：
//
//输入: "cbbd"
//输出: "bb"

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


