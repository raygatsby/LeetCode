//
// Created by eden on 18-10-18.
//


// 70.爬楼梯
// 斐波那契数列
// 做做简单题找找自信
class Solution {
public:
    int climbStairs(int n) {

        if(n<=2){
            return n;
        }
        int a = 1;
        int b = 2;
        int res;

        for(int i = 2;i<n;++i){
            res = a+b;
            a = b;
            b = res;
        }
        return res;
    }
};