//
// Created by eden on 18-11-14.
//

//129.求根到叶子节点数字之和
class Solution {
public:
    int sumNumbers(TreeNode* root) {

        vector<string> res;
        string tmp = "";
        dfs(root,res,tmp);
        int sum = 0;
        for(string s : res){
            sum += atoi(s.c_str()); //字符串转换为c类型字符串再用atoi函数
        }
        return sum;
    }

    void dfs(TreeNode *p,vector<string> &res,string &tmp){

        if(!p) return;
        // 找到叶子节点
        if(!p->left && !p->right){
            string s = " ";
            s[0] = p->val+'0';
            tmp += s;
            res.push_back(tmp);
            return;
        }

        string l = tmp;
        string r = tmp;

        // 往左搜索
        if(p->left){
            string s = " ";
            s[0] = p->val+'0';
            l += s;
            dfs(p->left,res,l);
        }

        // 往右搜索
        if(p->right){
            string s = " ";
            s[0] = p->val+'0';
            r += s;
            dfs(p->right,res,r);
        }
    }
};


// 0ms案例
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res=0;
        helper(root,res,0);

        return res;
    }

    void helper(TreeNode* root,int& res,int num){
        if(root==nullptr)
            return;

        num*=10;
        num+=root->val;

        if(root->right==nullptr && root->left==nullptr){
            res+=num;
            return;
        }

        helper(root->left,res,num);
        helper(root->right,res,num);
    }
};