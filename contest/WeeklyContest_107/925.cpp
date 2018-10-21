//
// Created by eden on 18-10-21.
//

//https://leetcode-cn.com/problems/long-pressed-name/


class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        int name_size = name.size();
        int typed_size = typed.size();

        int i,j;

        for( i = 0,j=0;i<name_size || j<typed_size;){

            //当ij匹配时可以都往前移
            if(name[i]==typed[j]){
                ++i;
                ++j;
            } else{

                if(typed[j]==name[i-1]){
                    // j不于i匹配可以尝试与i-1匹配
                    ++j;
                } else{
                    // 都不能匹配则返回false
                    return false;
                }
            }
        }

        if(i==name_size && j==typed_size)
            return true;
        return false;
    }
};