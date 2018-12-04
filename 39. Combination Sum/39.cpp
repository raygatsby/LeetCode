//
// Created by 许雷 on 2018/12/4.
//

//39.组合总和
//15.35
class Solution {
public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> res;
        if(candidates.size() == 0)
            return res;
        vector<int> tmp;
        helper(res,tmp,candidates,target,0,0);
        return res;
    }

    void helper(vector<vector<int>> &res,vector<int> &tmp,vector<int> &candidates,int target,int cur,int idx){

        if(cur == target){
            res.push_back(tmp);
            return;
        }
        int i = 0;

        // 只能往idx的后面递归 往前递归会有重复的
        for(i = idx;i<candidates.size();++i){
            if(candidates[i] + cur > target) // 这里直接跳过 以免递归深度过大
                continue;
            tmp.push_back(candidates[i]);
            helper(res,tmp,candidates,target,cur+candidates[i],i); // 每次递归到下一个数时 不能再往回递归 可以去重
            tmp.pop_back();
        }
    }
};