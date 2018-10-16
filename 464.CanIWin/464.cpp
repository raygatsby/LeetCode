//
// Created by 许雷 on 2018/10/15.
//

// 我能赢吗
// https://leetcode-cn.com/problems/can-i-win/

// 在搜索一个值是否用到的时候
// 开始想的是用一个 visit数组来标志一下
// 按照那条思路想下去 最终想的是每次对一个 dp[i][j] 求值时 然后用m遍历 i 来找出dp[i][j-m] 是否为真 如果 dp[i][j-m] 为假
// 顺势可以推断 这种情况保证会赢  关键就是 选了 m 之后 如果 dp[i][j-m] 又需要用到 m 就很不好办了
// 然后思维就乱了
//
// 本题只是有动态规划思想 没有相关代码

//
// curr 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 curr初值的后20位全表示是否选择了那个数 从右往左是 第 1位到第20位
// 这种网上看的方法
// 因为 可选的整数最大值为20 而一个int有32位 所以完全可以用一个int（curr）值 来表示当前选了哪些数 这个值初值为0 需要用到int的后20位
// 每次选择一个值 假如选的数是i 可以用 curr |（1<<(i-1)） 这个运算就可以让 curr的第 i 位变成 1
// 假如想 检测 i 是否被选  可以用  curr &（1<<(i-1)） 这个运算的结果来 判断

// 这种方法每个数是否被选就很容易标志
// 用递归就好办一点

class Solution {


public:
    map<int,bool> map1;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        if(maxChoosableInteger>=desiredTotal){
            return true;
        }
        if((maxChoosableInteger*maxChoosableInteger+maxChoosableInteger)/2<desiredTotal){
            return false;
        }
        return help(0,maxChoosableInteger,0,desiredTotal);
    }

    // help 函数其实是对游戏过程的模拟
    // curr 表示当前选择了哪些数
    bool help(int curr,int maxNumber,int sum,int total){

        if(map1.count(curr)){
            return map1[curr];
        }

        // 这就相当于 第一次选的数 从 1 到 maxNumber
        for(int i = 1;i<=maxNumber;++i){

            // 如果这个数被选过了
            // 就寻找下一个数
            if(curr & (1<<(i-1))){
                continue;
            }

            // 选择第i个数 用 新的一个当前值 new_curr 表示
            // 这样当下面递归查找时 返回结果后
            // curr 的值还是没有变化
            // 这段代码非常巧妙
            int new_curr = curr |(1<<(i-1));

            // 如果 已经选上这个数后 结果>=toal 或者 选了之后对方不能稳赢 则上面两种情况会让自己稳赢
            // 因为两个人都是采用最优策略
            // 所以实质上一个人不能稳赢就是另一个人会稳赢
            if(sum+i>=total || !help(new_curr,maxNumber,sum+i,total)){
                map1[curr] = true;
                return true;

            }
        }
        // 在循环里面没有返回 true 就说明这个状态不能稳赢
        map1[curr] = false;
        return false;
    }
};