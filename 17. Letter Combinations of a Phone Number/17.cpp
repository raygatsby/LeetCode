//
// Created by 许雷 on 2018/12/3.
//


//17.电话号码的字母组合
class Solution {
public:

    vector<vector<char>> chars{{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
                               {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0)
            return res;
        helper(res,digits,"",0);
        return res;
    }

    void helper(vector<string> &res,string &digits,string tmp,int idx){

        // 递归到最深处 保存字符串 然后返回
        if(idx == digits.size()){
            res.push_back(tmp);
            return;
        }

        for(int i = 0;i<chars[digits[idx]-'0'].size();++i){

            helper(res,digits,tmp + chars[digits[idx]-'0'][i],idx+1);
        }
    }
};