# 题目
>[https://leetcode-cn.com/problems/container-with-most-water/solution/]
# 题解
本题用两个指针，初始化一个指头一个指尾
将此时结果计算出来与res相比进行赋值
头尾两个指针哪个对应值小就把哪个改变
这样才能保证下次可能比当前值大