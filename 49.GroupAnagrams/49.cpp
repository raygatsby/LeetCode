//
// Created by eden on 18-10-20.
//

// 字母异位词分组
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int size = strs.size();
        int help[size][26];

        for(int i = 0;i<size;++i){
            for(int j = 0;j<26;++j){
                help[i][j] = 0;
            }
        }


        for(int i = 0;i<size;++i){
            for(char c : strs[i]){
                help[i][c-'a']++;
            }
        }

        vector<string> tmp;


        // 把每个字符串转换为 1a2b3c4d这种形式
        // 其实也可以直接排序
        for(int i  = 0;i<size;++i){
            string gg = "";
            for(int j = 0;j<26;j++){

                if(help[i][j] > 0){
                    string s = "00";
                    s[0] = (char)help[i][j];
                    s[1] = (char)j;
                    gg += s;
                }
            }
            tmp.push_back(gg);
        }

        map<string,vector<string>> map1;

        // 放到map里 可以把重复的都放在一起
        for(int i = 0;i<tmp.size();++i){
            map1[tmp[i]].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for(pair<string,vector<string>> p : map1){

            res.push_back(p.second);
        }
        return res;
    }

};