//
// Created by eden on 18-11-2.
//

//929.独特的电子邮件地址
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        set<string> help;

        for(string s : emails){

            int size = s.size();

            int pos;

            string qianmian = "";
            string houmian = "";

            for(int i = 0;i<size;i++){
                if(s[i]=='@'){
                    pos = i;
                    break;
                }
            }

            for(int i = pos+1;i<size;++i){
                houmian += s[i];
            }

            for(int i = 0;i<pos;++i){
                if(s[i]!='.'){
                    if(s[i]=='+'){
                        break;
                    }
                    qianmian += s[i];
                }
            }
            help.insert(qianmian+houmian);
        }
        return help.size();
    }
};