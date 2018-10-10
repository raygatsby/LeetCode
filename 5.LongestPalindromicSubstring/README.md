题目
====
https://leetcode-cn.com/problems/longest-palindromic-substring/
# 题解
本题有2种常规方法，复杂度都为O(n^2)<br>
1.动态规划法<br>
  先求出子串长度为1和2的回文标志，在以这个为基础求出子串长度为3的最长回文
  一直循环下去就可求得答案
2.中心扩展法<br>
   长度为 n 的字符串 共有 2n-1 个中心
   对每个中心进行向外扩展即可找出最长回文子串