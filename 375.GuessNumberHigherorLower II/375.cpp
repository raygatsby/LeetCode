//
// Created by 许雷 on 2018/10/12.
//

// 被题目坑了！！！ 还以为n为10的输出应该是 21 哎最后写出来还看了半天以为不对

class Solution {
public:
    int getMoneyAmount(int n) {

        int dp[n][n];
        for(int i = 0;i<n;++i){
            dp[i][i] = 0;
        }
        for(int l = 2;l<=n;++l){
            for(int i = 0;i<n-l+1;++i) {
                int j = i+l-1;
                // 上面3行在写动态规划题是出现过很多次

                // 以 m 位置为分割点 将【i，j】 分成 【i，m-1】 m 【m+1，j】
                int Min = dp[i][j-1]+j+1;  // m == j 的情况
                Min = min(i+1+dp[i+1][j],Min); // m == i 的情况
                for(int m=i+1;m<j;++m){

                    int left = dp[i][m-1];
                    int right = dp[m+1][j];
                    int tmp = m+1+max(left,right); // 以m为分割点时的需要钱数
                    // （这时应该选择在left和right较大的一边，才能满足题目说的确保赢得游戏）
                    Min = min(tmp,Min);
                }
                dp[i][j] = Min;
            }
        }
        return dp[0][n-1];
    }
};
