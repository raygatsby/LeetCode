//
// Created by 许雷 on 2018/11/7.
//


//721.账户合并
class Solution {
public:
    // 并查集数据结构
    vector<int> id;
    int find(int i){
        while (i!=id[i]){
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    void Union(int m,int n){
        int rootM = find(m);
        int rootN = find(n);
        if(rootM==rootN)
            return;
        id[rootN] = rootM;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int nums = accounts.size();  // 账户总数

        vector<set<string>> res(nums,set<string>());
        id = vector<int>(nums,0);

        for(int i=0;i<nums;++i){
            id[i] = i;
        }

        for(int i = 0;i<nums;++i){
            for(int next=i+1;next<nums;++next){

                if(accounts[i][0]!=accounts[next][0])  // 如果用户名都不相等直接跳过
                    continue;
                if(find(i)!=find(next)){  // 如果这两个账户已经在一起了直接跳过

                    for(int m=1;m<accounts[i].size();++m){
                        for(int n=1;n<accounts[next].size();++n){
                            if(accounts[i][m]==accounts[next][n]){
                                Union(i,next); // 有相等的就合并
                            }
                        }
                    }

                }
            }
        }

        for(int i = 0;i<nums;++i){
            int i_size = accounts[i].size();
            for(int j = 0;j<i_size;++j){
                res[find(i)].insert(accounts[i][j]);
            }
        }
        vector<vector<string> > re;
        for(int i = 0;i<nums;++i){
            if(res[i].size()!=0){
                vector<string> tt;
                for(string s : res[i]){
                    tt.push_back(s);
                }
                re.push_back(tt);
            }
        }
        return re;
    }
};