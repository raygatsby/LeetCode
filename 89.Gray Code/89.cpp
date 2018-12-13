//
// Created by 许雷 on 2018/12/13.
//

//89.格雷编码
class Solution {
public:
    vector<int> grayCode(int n) {

        if(n==0)
            return vector<int>({0});

        vector<int> res{0,1};

        helper(res,res,1,n);

        return res;

    }

    void helper(vector<int> &res,vector<int> tmp,int idx,int n){

        if(idx == n){
            return ;
        }

        res = tmp;  // 等价于把0加在前面
        for(int i = tmp.size()-1;i>=0;--i){
            // 把1加在前面 必须是逆序

            int tp = tmp[i];
            int count = 0;
            while (tp != 0){
                tp  = tp >> 1;
                ++count;
                cout << "sf";
            }
            res.push_back((int)pow(2,count));
        }

        helper(res,res,idx+1,n);
    }

};

