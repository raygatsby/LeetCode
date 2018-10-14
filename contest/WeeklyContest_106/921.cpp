//
// Created by eden on 18-10-14.
//

// 921. 使括号有效的最少添加
// https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) {

        int left = 0,right = 0;

        int sum = 0;

        for(char c : S ){

            if(c=='('){
                left++;
            } else {
                if(left>0){
                    left--;
                } else{
                    right++;
                }
            }
        }
        return left+right;
    }
};