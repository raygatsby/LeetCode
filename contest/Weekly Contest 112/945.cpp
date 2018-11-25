//
// Created by 许雷 on 2018/11/25.
//

//945.使数组唯一的最小增量
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {

        sort(A.begin(),A.end());

        int res = 0;
        int last = -1;
        for(int i=0;i<A.size();i++){
            if(A[i] > last){
                last = A[i];
            }else{
                res += (last-A[i]+1);
                last++;
            }
        }
        return res;
    }
};
