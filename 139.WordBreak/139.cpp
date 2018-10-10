//
// Created by 许雷 on 2018/10/10.
//


//这题做了2个小时才做出来，还是太菜了

//主要思路： 传统的动态规划去填格子，最终填好的各自是一个3角形 只有矩形的右上部分
// dp[j,i]表示从下标j到i的子串是否满足题意 具体看代码注释

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        bool dp[size][size];

        //前面常规初始化
        for(int i = 0;i<size;++i){
            for(int j = 0;j<size;++j){
                dp[i][j] = false;
            }
        }
        for (int i = 0; i < size; ++i) {
            if(contains(s.substr(i,1),wordDict))
                dp[i][i] = true;
            else
                dp[i][i] = false;
        }

        //外层循环是控制 对每个所求子串的长度
        for(int l = 2;l<=size;++l){
            // 内层循环 j 就是所求子串的起始下标
            for(int j = 0;j<size-l+1;++j){
                // 通过长度和起始下标计算终点下标 i
                int i = j+l-1;

                // 这个循环就是解题关键
                // 简单来说根据已经求的前面的部分子串来尝试拼出现在所求的子串
                for(int m = 0,n=j+1;m<=i-1&&n<=i;++m,++n){
                    if(dp[j][m]==true&&dp[n][i]==true&&m+1==n){
                        dp[j][i] = true;
                    }
                }
                // 先拼 拼不出来再到字典找 减少一点（常数）时间复杂度
                if(dp[j][i]==false){
                    dp[j][i] = contains(s.substr(j,l),wordDict);
                }
            }
        }
        return dp[0][size-1];
    }
    //  到字典里面找
    bool contains(string s,vector<string> & wordDict){
        for(int i = 0;i<wordDict.size();++i){
            if(wordDict[i]==s){
                return true;
            }
        }
        return false;
    }
};


//以下为递归暴力解法
//超时了

//        if(s==""){
//            return true;
//        }
//        vector<int> v1;
//        int size = wordDict.size();
//        for (int i = 0;i< size;++i) {
//
//            int cur_size = wordDict[i].size();
//            bool flag = true;
//            for (int j = 0; j < cur_size; ++j) {
//                if (wordDict[i][j] != s[j]) {
//                    flag = false;
//                }
//            }
//            if(flag){
//                v1.push_back(cur_size);
//            } else{
//                continue;
//            }
//        }
//        if(!v1.empty()){
//            for(int i : v1){
//                if(wordBreak(s.substr(i),wordDict)){
//                    return true;
//                } else{
//                    continue;
//                }
//            }
//        } else{
//            return false;
//        }
//        return false;
//    }