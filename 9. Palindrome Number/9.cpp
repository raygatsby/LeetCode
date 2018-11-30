//
// Created by eden on 18-11-30.
//

//9.回文数
class Solution {
public:
    bool isPalindrome(int x) {

        string s = to_string(x);

        int i = 0;
        int j = s.length()-1;
        while (i<=j){

            if(s[i]=s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;


    }
};