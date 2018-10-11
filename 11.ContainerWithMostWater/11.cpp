//
// Created by 许雷 on 2018/10/10.
//
//本题用两个指针，初始化一个指头一个指尾
//将此时结果计算出来与res相比进行赋值
//头尾两个指针哪个对应值小就把哪个改变
//这样才能保证下次可能比当前值大

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int res;
        int left = 0,right = height.size()-1;

        while (left<right){

            res = max(res,(right-left)*min(height[left],height[right]));

            if(height[left]<height[right]){
                left++;
            } else{
                right--;
            }
        }
        return res;
    }
};