//
// Created by 许雷 on 2018/11/25.
//


//946.验证栈序列
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        if(pushed.size()==0)
            return true;

        stack<int> stack1;

        for(int i=0;i<popped.size();){

            if(stack1.empty() && pushed.size()!=0){
                stack1.push(*pushed.begin());
                pushed.erase(pushed.begin());
            }

            int top = stack1.top();
            if(top!=popped[i]){
                // 栈顶元素不是出栈序列的元素
                bool  find = false;
                while (!pushed.empty()){   // 把待入栈元素入栈

                    stack1.push(*pushed.begin());
                    pushed.erase(pushed.begin());

                    if(stack1.top()==popped[i]){
                        i++;
                        stack1.pop();
                        find = true;
                        break;
                    }
                }
                if(!find)
                    return false;
            }else{
                stack1.pop();
                i++;
            }
        }
        return true;
    }
};
