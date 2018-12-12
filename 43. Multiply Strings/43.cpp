//
// Created by 许雷 on 2018/12/12.
//

//43.字符串相乘
class Solution {
public:
    string multiply(string num1, string num2) {

        int len1 = num1.length();
        int len2 = num2.length();


        //用短的数去乘大的数
        if(len1 > len2){
            swap(len1,len2);
            swap(num1,num2);
        }

        if(len1==1 && num1[0]=='0')
            return "0";

        // 将字符串反装过来 容易计算
        helper(num1);
        helper(num2);

        vector<string> tmps;

        int Max = INT_MIN;

        // 每位相乘 模拟真实计算
        for(int i = 0;i<len1;i++){

            string tmp(i,'0');
            int jw = 0;

            for(char c : num2){

                int tp = (c-'0') * (num1[i]-'0') + jw;
                tmp += (tp%10 + '0');
                jw = tp/10;
            }

            if(jw != 0){
                tmp += (jw + '0');
            }
            Max = max(Max,(int)tmp.length());
            tmps.push_back(tmp);
        }
        // 乘完后结果存再一个字符串数组中
        // 在将她们累加起来


        string res = "";
        int jw = 0;
        for(int i = 0;i<Max;i++){
            int tp = jw;
            for(string s : tmps){
                if(i < s.length()){
                    tp += s[i]-'0';
                }
            }

            res += tp%10+'0';
            jw = tp/10;
        }

        if(jw != 0){
            res += jw+'0';
        }
        helper(res);
        return res;

    }

    //反转字符串
    void helper(string &str){

        string tmp = str;
        int len = str.size();
        for(int i = 0;i<len;++i){
            tmp[i] = str[len-i-1];
        }
        str =  tmp;
    }
};