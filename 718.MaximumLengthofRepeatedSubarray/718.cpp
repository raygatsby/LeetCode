//
// Created by 许雷 on 2018/10/22.
//
//8.55
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {

        int size_A = A.size();
        int size_B = B.size();
        int res[1000][1000] = {0};


        int re = INT_MIN;

        // 对边界进行初始化
        for(int i = 0;i<size_A;++i){
            if(B[0]==A[i]){
                res[0][i] = 1;
                re = max(re,res[0][i]);
            }
        }

        for(int i = 0;i<size_B;++i){
            if(A[0]==B[i]){
                res[i][0] = 1;
                re = max(re,res[i][0]);
            }
        }


        for(int i = 1;i<size_B;++i){
            for(int j = 1;j<size_A;++j){
                if(B[i]==A[j]){
                    // 如果这两个数相等
                    // 因为得是连续的子数组
                    // 所以 用dp[i-1][j-1]加一即可
                    res[i][j] = res[i-1][j-1]+1;
                } else{
                    // 不相等置为0
                    res[i][j] = 0;
                }
                // 在循环过程中保存最大值
                re = max(re,res[i][j]);
            }
        }
        return re;
    }
};