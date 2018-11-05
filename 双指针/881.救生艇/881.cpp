//
// Created by 许雷 on 2018/11/4.
//

//14.19
//881
// 双指针
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        int size = people.size();
        // 先排序
        sort(people.begin(),people.end());
        int res = 0;
        int l = 0;
        int r = size-1;
        while (l<r){

            if(people[l]+people[r]<=limit){
                // 能够装下这两个人
                ++l;
                --r;
                ++res;
            }else{
                // 装不下就只能大的先装了
                ++res;
                --r;
            }
        }
        if(l==r){
            ++res;
        }
        return res;
    }
};
