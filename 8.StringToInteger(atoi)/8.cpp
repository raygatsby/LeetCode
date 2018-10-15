//
// Created by 许雷 on 2018/10/10.
//

#include <string>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;


class Solution {
public:
    int myAtoi(string str) {

        if(str.size()==0){
            return 0;
        }

        vector<int> num;  // 存储数字部分
        bool is_zs;  // 正数还是负数

        int pos;
        for(int i = 0;i<str.size();++i){
            char c = str[i];
            if(c!=' '){
                pos = i;
                if((c=='+')||(c>='0'&&c<='9')){
                    is_zs = true;
                    break;
                } else if(c=='-'){
                    is_zs = false;
                    break;
                } else{
                    return 0;
                }
            }
        }

        if(str[pos]=='+'||str[pos]=='-'){
            pos++;
        }


        for(int i = pos;i!=str.size();++i){
            if(str[i]<'0'||str[i]>'9'){
                break;
            }
            // 将每个合法数字存储在vector里面
            num.push_back(str[i]-'0');
        }

        // 有效数字位数
        int not0zize = 0;
        for(int i = 0;i<num.size();++i){
            if(num[i]!=0){
                // i 是从左往右第一个不为0的数的下标
                not0zize = num.size()-i;
                break;
            }
        }

        if(not0zize==0)
            return 0;
        // 溢出
        if(not0zize>10){
            if(is_zs) return INT_MAX;
            else return INT_MIN;
        }
        long long result = 0;

        for(int i = 0;i!=num.size();++i){
            result += num[i]*pow(10,num.size()-i-1);
        }

        if(is_zs){
            if (result>INT_MAX){
                return INT_MAX;
            } else{
                return result;
            }
        } else{
            if(-result<INT_MIN){
                return INT_MIN;
            } else{
                return -result;
            }
        }
    }
};