//
// Created by eden on 18-11-30.
//


//122. 买卖股票的最佳时机 II
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int res = 0;
        for(int i=1;i<prices.size();++i){

            if(prices[i] > prices[i-1])
                res += (prices[i] - prices[i-1]);
        }
        return res;
    }
};