//
// Created by eden on 18-11-21.
//

//7.整数反转
class Solution {
public:
    int reverse(int x) {

        bool flag = false;
        if(x < 0){
            x = -x;
            flag = true;
        }
        string s = to_string(x);
        string tmp = s;
        for(int i=0;i<s.size();++i){
            tmp[i] = s[s.size()-i-1];
        }

        long res = 0;
        for(int i = 0;i<tmp.size();i++){
            res += (tmp[i]-'0') * pow(10,tmp.size()-i-1);
        }

        cout << res;

        if(!flag && res > INT_MAX){
            return 0;
        }
        if(flag && -res < INT_MIN){
            return 0;
        }

        if(flag)
            res = -res;
        return res;

    }
};
