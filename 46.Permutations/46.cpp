//
// Created by 许雷 on 2018/11/28.
//

//46.全排列
//18.52
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> res;
        dfs(nums,0,res);
        return res;
    }

    void dfs(vector<int> &nums,int index,vector<vector<int>> &res){

        if(index == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){

            int tmp = nums[i];
            nums[i] = nums[index];
            nums[index] = tmp;
            cout << "swapbefore:" << nums[i] << " " << nums[index] << endl;
            dfs(nums,index+1,res);
            cout << "swapafter:" << nums[i] << " " << nums[index] << endl;
            tmp = nums[i];
            nums[i] = nums[index];
            nums[index] = tmp;

        }
    }
};