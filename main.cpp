#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cmath>
#include <map>
#include <list>
#include <cstring>
#include <vector>
#include <set>
#include <string.h>
#include <set>
#include <unordered_map>
#include <stack>
#include <unistd.h>

using namespace std;
// 576. 出界的路径数
// 3维dp

#if 0
//执行用时为 4 ms 的范例
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        for (int k = 1; k <= N; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    long long a = i == 0 ? 1 : dp[k - 1][i - 1][j];
                    long long b = i == (m-1) ? 1 : dp[k - 1][i + 1][j];
                    long long c = j == (0) ? 1 : dp[k - 1][i][j-1];
                    long long d = j == (n - 1) ? 1 : dp[k - 1][i][j+1];
                    dp[k][i][j] = (a + b + c + d)%(1000000007);
                }
            }
        }
        return dp[N][i][j];
    }
};
#endif


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 乘积最大的子序列 （含约束条件）
void func(){
    int n,k,d;
    cin >> n;
    int stu[n+5];
    for(int i = 1;i<=n;++i){
        cin >> stu[i];
    }
    cin >> k >> d;

    long long dp_max[k+5][n+5];
    long long dp_min[k+5][n+5];
    long long res;

    res = LONG_LONG_MIN ;
    for(int i = 1;i<=n;i++){
        dp_max[1][i] = dp_min[1][i] = stu[i];

        for(int m=2;m<=k;++m){
            for(int j = i-1;i-j<=d && j>=1;j--){
                dp_max[m][i] = max(dp_max[m][i],max(dp_max[m-1][j]*stu[i],dp_min[m-1][j]*stu[i]));
                dp_min[m][i] = min(dp_min[m][i],min(dp_max[m-1][j]*stu[i],dp_min[m-1][j]*stu[i]));
            }

        }
        res = max(res,dp_max[k][i]);
    }
    printf("%lld\n",res);
}
