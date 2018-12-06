//
// Created by eden on 18-12-6.
//

//47.全排列II
class Solution {
        public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {

            vector<vector<int>> res;
            dfs(nums,0,res);
            return res;
        }

        void dfs(vector<int> &nums,int index,vector<vector<int>> &res){

            if(index == nums.size()){
                res.push_back(nums);
                return;
            }

            unordered_set<int> set1;
            for(int i=index;i<nums.size();i++){

                // 如果
                if(set1.count(nums[i]) != 0)
                    continue;

                set1.insert(nums[i]);

                swap(nums[i],nums[index]);
                dfs(nums,index+1,res);
                swap(nums[i],nums[index]);

            }
        }
};