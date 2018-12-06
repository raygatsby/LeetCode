//
// Created by 许雷 on 2018/12/5.
//


//40.组合总和 II
class Solution {
public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> res;
        if(candidates.size() == 0)
            return res;
        vector<int> tmp;
        // 这个需要先排序 而上一题里就不需要排序
        sort(candidates.begin(),candidates.end()); // 先排序  在递归过程中 检查当前值与前一个值 如果相等就直接跳过 可以避免出现重复的
        helper(res,tmp,candidates,target,0,0);
        return res;
    }

    void helper(vector<vector<int>> &res,vector<int> &tmp,vector<int> &candidates,int target,int cur,int idx){

        if(cur == target){
            res.push_back(tmp);
            return;
        }

        // 只能往idx的后面递归 往前递归会有重复的
        for(int i = idx;i<candidates.size();++i){

            if(i == idx || candidates[i] != candidates[i-1]){  //只有不相等时才可以进去递归
                if(candidates[i] + cur > target) // 这里直接跳过 以免递归深度过大
                    continue;
                tmp.push_back(candidates[i]);
                helper(res,tmp,candidates,target,cur+candidates[i],i); // 每次递归到下一个数时 不能再往回递归 可以去重
                tmp.pop_back();
            }
        }
    }
};
