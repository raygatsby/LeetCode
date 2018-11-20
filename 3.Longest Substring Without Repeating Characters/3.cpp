//
// Created by eden on 18-11-20.
//

//3.无重复字符的最长子串
// 用hashset解法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t size = s.size();
        int res = 0;
        unordered_set<char> set1;
        for(int i=0,j=0;j<size && i<size;){

            if(set1.count(s[j]) == 0){
                set1.insert(s[j++]);
                res = max(res,j-i);
            }else{
                set1.erase(s[i]);
                i++;
            }
        }
        return res;
    }
};

//hash_map最优解法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t size = s.size();
        int res = 0;

        unordered_map<char,int> map1;

        for(int i=0,j=0;j<size;j++){

            if(map1.count(s[j]) != 0){
                i = max(i,map1[s[j]]);
            }
            res = max(res,j-i+1);
            map1[s[j]] = j+1;
        }

        return res;
    }
};

//用字符集数组来实现跟hashmap一样的效果
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t size = s.size();
        int res = 0;
        int chars[256] = {0};

        for(int i=0,j=0;j<size;++j){
            i = max(i,chars[s[j]]);
            res = max(res,j-i+1);
            chars[s[j]] = j+1;
        }
        return res;
    }
};