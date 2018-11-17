//
// Created by 许雷 on 2018/11/17.
//

// 121.买卖股票的最佳时机
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int res = 0,buy = INT_MAX;
        for(int i=0;i<prices.size();++i){
            buy = min(buy,prices[i]);         // 找到当前为止最小的值作为买入
            res = max(res,prices[i] - buy);    // 将之前的最大值与新产生的利润比较  看是否更新
        }
        return res;
    }
};