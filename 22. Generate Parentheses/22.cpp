//
// Created by 许雷 on 2018/12/3.
//

//22.括号生成
class Solution {
public:
    // 在生成过程中，左括号的个数要大于等于右括号的个数
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        helper(res,"",0,0,n);
        return res;
    }

    void helper(vector<string> &res,string tmp,int left,int right,int n){
        if(left == right && right==n){
            res.push_back(tmp);
            return;
        }else if(left == n){
            helper(res,tmp+')',left,right+1,n); // 左括号全部用了
        } else if(left==right){
            helper(res,tmp+'(',left+1,right,n); // 左括号与右括号个数相等 只能加左括号
        }else if(left > right){
            helper(res,tmp+'(',left+1,right,n); // 左括号比有括号多 且左括号数还不等于n 则时候左右括号都可以加
            helper(res,tmp+')',left,right+1,n);
        }
    }
};