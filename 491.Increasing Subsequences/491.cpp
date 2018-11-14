//
// Created by 许雷 on 2018/11/14.
//

// 491.递增子序列
class Solution {
public:
    set<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        size_t size = nums.size();
        for(int i = 0;i<size;++i){
            vector<int> tmp{nums[i]};
            dfs(tmp,nums,i);   // 对每个起点进行dfs搜索
        }
        vector<vector<int>> ok;

        for(vector<int> vector1 : res){
            ok.push_back(vector1);  // 把set里的转移到vector里
        }
        return ok;
    }

    void dfs(vector<int> &tmp,vector<int> &nums,int cur){
        size_t size = nums.size();
        if(cur >= size-1) return;

        for(int i=cur+1;i<size;++i){

            if(nums[i] >= nums[cur]){
                vector<int> en = tmp;   // 必须保证tmp不能被改变  这世上一个传进来的
                en.push_back(nums[i]); // en是符合条件的序列
                res.insert(en);  // 把en加入到res中可以去重
                dfs(en,nums,i);  // 向下接着搜索
            }
        }
    }
};
