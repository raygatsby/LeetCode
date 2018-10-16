//
// Created by 许雷 on 2018/10/16.
//

// 898.子数组按位或操作
//https://leetcode-cn.com/problems/bitwise-ors-of-subarrays/

// 这题数据太大了 如果用传统 dp 一定超时
// 不过有很多重复计算
// 可以用set来保存  以前dp中的每一行
// 这样可以减少重复计算量
class Solution {
public:

    set<int> set1;
    int subarrayBitwiseORs(vector<int>& A) {

        int size = A.size();
        if(size == 0){
            return 0;
        }
        set<int> set1;
        set<int> dp1;
        set<int> dp2;
        dp1.insert(A[0]);
        set1.insert(A[0]);
        for(int i = 1;i<size;++i){

            // 这里用两个set 交替保存 两行的值
            // 从上一个set 的每个值 与当前值 进行或 就可以得到 当前set
            if(i%2==1){
                for(int d1 : dp1){
                    dp2.insert(d1|A[i]);
                    set1.insert(d1|A[i]);
                }
                // 最后插入当前值
                dp2.insert(A[i]);
                // 本行已经求完删除上一行进行下次迭代
                dp1.clear();
            } else{
                for(int d2 : dp2){
                    dp1.insert(d2|A[i]);
                    set1.insert(d2|A[i]);
                }
                dp1.insert(A[i]);
                dp2.clear();
            }
            set1.insert(A[i]);
        }
        return set1.size();
    }
};