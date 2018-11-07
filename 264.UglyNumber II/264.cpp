//
// Created by 许雷 on 2018/11/7.
//

// 264.丑数 2
class Solution {
public:
    int nthUglyNumber(int n) {
        int res[1690];
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        res[0] = 1;
        for(int i = 1;i<1690;++i){
            res[i] = min(min(res[i2]*2,res[i3]*3),res[i5]*5);

            if(res[i]==res[i2]*2)
                ++i2;
            if(res[i]==res[i3]*3)
                ++i3;
            if(res[i]==res[i5]*5)
                ++i5;
        }
        return res[n-1];
    }
};
