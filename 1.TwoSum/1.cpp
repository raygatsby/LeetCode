//
// Created by eden on 18-11-19.
//

class Solution {
public:

    typedef struct node{

        int _val;
        int _index;
        node(int val,int index) : _val(val),_index(index){};

    }node;

    bool static cmp(node i,node j){
        return i._val < j._val;
    }

    vector<int> twoSum(vector<int>& nums, int target) {

        size_t size = nums.size();
        vector<node> nodes;

        for(int i=0;i<size;++i){
            nodes.push_back(node(nums[i],i));
        }

        sort(nodes.begin(),nodes.end(),cmp);
        int l = 0;
        int r = size -1 ;
        vector<int> res;

        while(l<r){

            int cur = nodes[l]._val+nodes[r]._val;

            if(cur < target)
                l++;
            else if(cur > target)
                r--;
            else{
                res.push_back(nodes[l]._index);
                res.push_back(nodes[r]._index);
                break;
            }
        }
        return res;
    }
};
