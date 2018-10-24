//
// Created by 许雷 on 2018/10/23.
//

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        int dp[10001];
        int sum[10001] = {0};

        int size = nums.size();

        for(int i = 0;i<size;++i){
            // 每个数的所有重复值加起来
            // 比如 2 2 3 3 3 4 这个歌数组
            // 则 num[2] = 4
            sum[nums[i]] += nums[i];
        }

        dp[0] = 0;
        dp[1] = sum[1];
        for(int i=2;i<=10000;++i){
            // 对每个数 选着他之后就不能选他的前一个数
            // 所以有一个状态转移方程
            // 取最大值
            dp[i] = max(dp[i-1],dp[i-2]+sum[i]);
        }
        return dp[10000];
    }
};

//11.34
// 开始写的超时
//删除与获得点数
#if 0
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        int size = nums.size();

        if(size==0){
            return 0;
        }

        sort(nums.begin(),nums.end());

        long long dp[size][size];

        for(int i = 0;i<size;++i){
            for(int j = 0;j<size;++j){
                dp[i][j] = 0;
            }
            dp[i][i] = nums[i];
        }



        long long res = 0;

        for(int l = 2;l<=size;++l){
            for(int i = 0;i<size-l+1;++i){
                int j = i+l-1;
                long long Max = LONG_LONG_MIN;

                for(int k = i;k<=j;++k){
                    if(k!=i && nums[k]==nums[k-1]){
                        Max = dp[i][j];
                        break;
                    }


                    long long tmp = 0;
                    int left,right;
                    for(left=k;left>=i;--left){
                        if(nums[left]==nums[k]){
                            tmp+=nums[left];
                            if(left==i){
                                break;
                            }

                        }else if(nums[left]!=nums[k]-1 || left==i){
                            break;
                        }
                    }

                    if(nums[left]!=nums[k] && nums[left]!=nums[k]-1){
                        tmp += dp[i][left];
                    }

                    for(right=k;right<=j;++right){

                        if(nums[right]==nums[k]){
                            tmp+=nums[right];
                            if(right==j){
                                break;
                            }
                        } else if(nums[right]!=nums[k]+1 || right==j){
                            break;
                        }
                    }

                    if(nums[right]!=nums[k] && nums[right]!=nums[k]+1){
                        tmp+=dp[right][j];
                    }

                    tmp -= nums[k];
                    Max = max(Max,tmp);
                }
                dp[i][j] = Max;
            }
        }
        return dp[0][size-1];
    }
};
#endif