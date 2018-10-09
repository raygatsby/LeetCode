//
// Created by 许雷 on 2018/10/9.
//

//这题没啥取巧的
// 暴力 憨算


#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=0)
            return NULL;
        if(numRows==1)
            return s;
        vector<char> v[numRows];
        int count = 0;
        int size = s.size();
        for(int index = 0;index<size;++index){
            if(count==(numRows-1))
                count = 0;
            int temp = count%numRows;
            if(temp==0){
                for (int i = 0; i < numRows; ++i) {
                    v[i].push_back(s[index]);
                    if(i!=numRows-1)
                        index++;
                    if(index>=size)
                        break;
                }
            } else{
                v[numRows-temp-1].push_back(s[index]);
            }
            count++;
        }
        string res = "";
        for (int i = 0; i < numRows; ++i) {
            for(auto c = v[i].begin();c!=v[i].end();++c){
                res += *c;
                cout << *c;
            }
            cout << endl;
        }


        return res;
    }
};
