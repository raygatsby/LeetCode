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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//141.判断链表是否有环
#if 0
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(!head)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast){
            if(fast->next)
                fast = fast->next->next;
            else
                return false;
            slow = slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
};
#endif

// 142.找出链表环的位置
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(!head)
            return NULL;

        ListNode *fast = head;
        ListNode *slow = head;


        while (fast){
            if(fast->next)
                fast = fast->next->next;
            else
                return NULL;
            slow = slow->next;
            if(fast==slow){
                // 有环时
                slow = head;
                while (fast!=slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};

int main() {

    vector<int> vector1{0,2,1,-3};


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
