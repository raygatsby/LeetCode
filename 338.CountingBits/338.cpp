//
// Created by 许雷 on 2018/10/21.
//

// 计算比特位
//https://leetcode-cn.com/problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int num) {

        vector<int> res;
        res.push_back(0);

        // 利用已经求出来的值
        for(int i = 1;i<=num;++i){

            if(i%2==1){
                // 奇数直接把前一个数的比特位数加1
                res.push_back(res[i-1]+1);
            }else{

                // 偶数可以拆成 i  = i/2 +i/2
                if(res[i/2]==1){
                    // 如果i/2是一个特殊的数 即是2的整数次幂
                    // 则这个数也是 直接等于1
                    res.push_back(1);
                }else{
                    // 否则就等与 res[i/2]
                    res.push_back(res[i/2]);
                }
            }

        }
        return res;

    }
};