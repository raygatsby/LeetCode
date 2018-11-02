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

////1
//class Solution {
//public:
//    int numUniqueEmails(vector<string>& emails) {
//
//        set<string> help;
//
//        for(string s : emails){
//
//            int size = s.size();
//
//            int pos;
//
//            string qianmian = "";
//            string houmian = "";
//
//            for(int i = 0;i<size;i++){
//                if(s[i]=='@'){
//                    pos = i;
//                    break;
//                }
//            }
//
//            for(int i = pos+1;i<size;++i){
//                houmian += s[i];
//            }
//
//            for(int i = 0;i<pos;++i){
//                if(s[i]!='.'){
//                    if(s[i]=='+'){
//                        break;
//                    }
//                    qianmian += s[i];
//                }
//            }
//            help.insert(qianmian+houmian);
//        }
//        return help.size();
//    }
//};



//class Solution {
//public:
//    int numSubarraysWithSum(vector<int>& A, int S) {
//
//        int size = A.size();
//        long long res = 0;
//
//        if(size < S){
//            return 0;
//        }
//
//        if(size==0){
//            return 0;
//        }
//        //dp[i]表示前 i 个数的和
//        int dp[size+1];
//        dp[0] = 0;
//        for(int i = 1;i<=size;++i){
//            dp[i] = dp[i-1]+A[i-1];
//            for(int j = i;j>=1 && i-j+1>=S;--j){
//
//                if(i-j+1>=S){
//                    //dp[i] 在退出内层循环时 值为变成前i个数的和
//                    // 在此之前 dp【i】 表示从下标 j 到 i 的数组值的和
//                    dp[i] = dp[i-1] - dp[j-1] + A[i-1];
//
//                    if(dp[i]==S){
//                        res++;
//                    }
//                }
//
//            }
//        }
//        return res;
//    }
//};

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int size = nums.size();
        int closest = INT_MAX;
        if(size<3){
            return 0;
        }
        sort(nums.begin(),nums.end());

        for(int i = 0;i<size-1;++i){

            // 对于 nums[i] 在下面while循环里就找出含有这个 nums[i] 的全部值
            // 所以再遇到 nums[i] 可以直接跳过 不进入循环
            if(i==0 || nums[i] != nums[i-1] ){
                int key = target-nums[i];

                int j = i+1;
                int k = size-1;

                // nums[j] < nums[k]
                // j到k是一个单调不减数列
                // 所以 如果 nums[j] + nums[k] > key 则应该改变 k的值
                // 反之亦然
                while (j<k){

                    int delta = target -( nums[i]+nums[j]+nums[k]);

                    if(delta==0){
                        return target;
                    }

                    if(abs(closest)>abs(delta)){
                        closest = delta;
                    }
                    if(delta>0)
                        j++;
                    else
                        k--;
                }
            }
        }
        return target-closest;
    }
};




int main() {

    vector<int> vector1{0,2,1,-3};
    Solution s;
    cout << s.threeSumClosest(vector1,1);

#if 0
    vector<vector<int >> v{{1},{0}};

    int p1[100];
    int *p2 = (int *)malloc(sizeof(int)*100);

    memset(p2,0,sizeof(int)*100);

    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;

    *(p2+1) = 100;
    cout << p2[10];
#endif

}
