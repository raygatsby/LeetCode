//
// Created by 许雷 on 2018/10/18.
//

// 576.出界的路径数

class Solution {
public:
    vector<vector<int>> moves{{-1, 0}, {1, 0}, {0,-1}, {0,1}};
    long long res = 0;
    const int mod = (int)1e9+7;

    int findPaths(int m, int n, int N, int i, int j) {

        long long dp[51][51][51];
        memset(dp,0, sizeof(dp));
        dp[i][j][0] = 1;

        for(int l = 0;l<N;++l){
            for(int i = 0;i<m;++i){
                for(int j = 0;j<n;++j){
                    // 只判断起始点和起始点走到的位置
                    if(dp[i][j][l]>0){
                        for(vector<int> move : moves){
                            int x = i+move[0];
                            int y = j+move[1];

                            if (isOut(x,y,m,n)){
                                // 出界了
                                res += dp[i][j][l];
                                res %= mod;
                            } else{
                                // 没有出界 则下次 遍历会检查 (x,y)
                                dp[x][y][l+1] += dp[i][j][l];
                                dp[x][y][l+1] %= mod;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }

    // 判断是否出界
    bool isOut(int x,int y,int m,int n){
        return x<0 || x>=m || y<0 || y>=n;
    }

    // 暴力搜索 会超时
    void dfs(int i,int j,int m,int n,int count,int N){
        if(count>N){
            return;
        }
        if(isOut(i,j,m,n)){
            res++;
            res = res % mod;
            return ;
        }
        for(vector<int> move : moves){
            int x = move[0]+i;
            int y = move[1]+j;
            dfs(x,y,m,n,count+1,N);
        }
    }
};