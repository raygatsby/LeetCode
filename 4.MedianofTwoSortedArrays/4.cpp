//
// Created by 许雷 on 2018/10/9.
//
//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
//
//请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
//
//你可以假设 nums1 和 nums2 不同时为空。
//
//示例 1:
//
//nums1 = [1, 3]
//nums2 = [2]
//
//中位数是 2.0
//示例 2:
//
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//中位数是 (2 + 3)/2 = 2.5

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m>n){
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            int tmp = m;
            m = n;
            n = tmp;
        }

        int x = (m+n+1)/2; // 这步决定了当 m+n为技术时 中位数 在左边还是在右边 如果写为 （m+n）/2 那时中位数就在右边

        int low = 0,high = m;

        // 这里与传统在二分查找里有一个很重要的区别
        // 传统是对下标进行二分 范围是 【0，m-1】
        //而这里的 i 只是决定要从第一个数组里选几个放在左边
        //所以 i 的范围是 【0，m】
        // i=0和i=m是两种特殊情况 得特殊考虑
        while (low<=high){
            int i = (low+high)/2;
            int j = x-i;

            if(i>low&&nums1[i-1]>nums2[j]){
                high = i - 1;
            } else if(i<high&&nums2[j-1]>nums1[i]){
                low  = i + 1;
            } else{

                int left_max;
                if(i==0){
                    left_max = nums2[j-1];
                } else if(j==0){
                    left_max = nums1[i-1];
                } else{
                    left_max = max(nums1[i-1],nums2[j-1]);
                }

                int right_min;

                if(i==m){
                    right_min = nums2[j];
                } else if(j==n){
                    right_min = nums1[i];
                } else{
                    right_min = min(nums1[i],nums2[j]);
                }

                if((m+n)%2==1){
                    return left_max;
                } else{
                    return (left_max+right_min)/2.0;
                }
            }
        }
        return 0.0;


    }
};