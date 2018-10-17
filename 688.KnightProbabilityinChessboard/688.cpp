//
// Created by eden on 18-10-17.
//

// 19.10
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {

        vector<vector<int>> move{{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};

        vector<vector<double >> dp(N,vector<double >(N,1));

        // 总共要走K次
        for(int l = 0;l<K;l++){

            vector<vector<double >> dpl(N,vector<double >(N,0));

            for(int i = 0;i<N;++i){
                for(int j = 0;j<N;++j){

                    for(vector<int> v : move){
                        // 每个可能走的地方
                        int x = v[0] + i;
                        int y = v[1] + j;

                        // 如果(x,y) 符合条件
                        // 则可以从x,y走到 i,j
                        // 所以到达 i,j 路程数就可以加上 dp[x][y];
                        if(notOut(x,y,N)){
                            dpl[i][j] += dp[x][y];
                        }
                    }
                }
            }

            dp = dpl;
        }
        return dp[r][c]/pow(8,K);
    }

    // 判断是否出界
    // 返回为 true 时没有出界
    bool notOut(int x,int y,int N){
        return x>=0 && y>=0 && x<N && y<N;
    }

};