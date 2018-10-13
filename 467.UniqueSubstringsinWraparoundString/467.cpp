//
// Created by 许雷 on 2018/10/13.
//

// https://leetcode-cn.com/problems/unique-substrings-in-wraparound-string/description/
// 环绕字符串中唯一的子字符串

#include <string>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {

        int size = p.size();

        // Max数组记录 以这个字符结尾的所有子串个数

        // 比如 假如以 a 结尾的所有子串中最大长度为 100 则这个 子串包含了其他所有 以a结尾的子串
        // 所以以 a 结尾的子串个数为 100
        int Max[26] = {0};
        int count = 0;
        int res = 0;
        for(int i = 0;i<size;++i){

            if((p[i]==p[i-1]+1)||(p[i-1]=='z'&&p[i]=='a')){
                count++;
            } else{
                count = 1;
            }
            Max[p[i]-'a'] = max(Max[p[i]-'a'],count);
        }
        for(int n : Max){
            res += n;
        }
        return res;
    }
};