//
// Created by 许雷 on 2018/11/7.
//

//263.丑数
class Solution {
public:
    bool isUgly(int num) {
        if(num==0)
            return false;

        if(num==1 || num==2 || num==3 || num==5){
            return true;
        } else if(num%2==0){
            return isUgly(num/2);
        } else if(num%3==0){
            return isUgly(num/3);
        } else if(num%5==0){
            return isUgly(num/5);
        } else
            return false;
    }
};