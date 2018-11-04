//
// Created by 许雷 on 2018/11/4.
//


//935
class Solution {
public:
    double knightProbability(int N) {

        vector<vector<int>> move{{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};

        vector<vector<int >> dp(4,vector<int >(3,1));
        int res = 0;

        for(int l = 0;l<N-1;l++){

            vector<vector<int >> dpl(4,vector<int >(3,0));

            for(int i = 0;i<4;++i){
                for(int j = 0;j<3;++j){

                    if((i>=0&&j>=0&&i<=2&&j<=2)||(i==3&&j==1)){
                        for(vector<int> v : move){
                            // 每个可能走的地方
                            int x = v[0] + i;
                            int y = v[1] + j;

                            // 如果(x,y) 符合条件
                            // 则可以从x,y走到 i,j
                            // 所以到达 i,j 路程数就可以加上 dp[x][y];
                            if((x<=2&&y<=2&&x>=0&&y>=0)||(x==3&&y==1)){
                                dpl[i][j] += dp[x][y];
                                dpl[i][j] %= (int)1e9+7;
                            }
                        }
                    }
                }
            }
            dp = dpl;
        }

        for(int i = 0;i<4;++i){
            for(int j = 0;j<3;++j){
                if((i>=0&&j>=0&&i<=2&&j<=2)||(i==3&&j==1)){
                    res += dp[i][j];
                    res %= (int)1e9+7;
                }
            }
        }
        return res;
    }
};