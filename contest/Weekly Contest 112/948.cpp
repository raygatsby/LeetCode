//
// Created by 许雷 on 2018/11/25.
//

//948.令牌放置
//16.00
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {

        if(tokens.size() == 0)
            return 0;

        sort(tokens.begin(),tokens.end());
// 排序后 能量换分必然是换最左边的能量   分换能量必然是换最右边的能量
// 设置两个指针 一个指向数组头部 一个数组尾部即可
        int Max = 0;
        int i = 0,j = tokens.size()-1;
        int cur = 0;
        while (i<=j){

            if(tokens[i] <= P){
                cur++;
                P = P-tokens[i];
                i++;
                Max = max(Max,cur);
            }else if(cur > 0){
                cur--;
                P = P+tokens[j];
                j--;
            } else{
                break;
            }
        }
        return Max;
    }
};