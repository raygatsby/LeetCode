//
// Created by eden on 18-10-14.
//

// 922.按奇偶排序数组 II
// https://leetcode-cn.com/problems/sort-array-by-parity-ii/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {

        vector<int> ou;
        vector<int> ji;

        int size = A.size();
        for(int i = 0;i<size;++i){

            if(A[i]%2==0){
                ou.push_back(A[i]);
            } else{
                ji.push_back(A[i]);
            }
        }

        int m = 0;
        int n = 0;
        for(int i = 0;i<size;i++){
            if(i%2==0){
                A[i] = ou[m];
                m++;
            } else{
                A[i] = ji[n];
                n++;
            }
        }
        return A;
    }
};