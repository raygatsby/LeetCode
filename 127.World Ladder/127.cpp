//
// Created by 许雷 on 2018/11/15.
//

//127.单词接龙
#if 1
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res=1;
        unordered_set<string> list{wordList.begin(),wordList.end()};  // 把词典存在哈希set里面
        queue<string> q;                                 // 队列用来做BFS
        q.push(beginWord);
        unordered_set<string> visit;                 // visit保存已经访问过的单词
        while (!q.empty()){

            size_t q_size = q.size();
            ++res;
            while (q_size-->0){

                string cur = q.front();
                q.pop();
                visit.insert(cur);
                for(int i=0;i<cur.size();++i){
                    char mychar = cur[i];
                    for(char c='a';c<='z';++c){  // 对当前单词 循环改变他的每个位置 看是否在词典里// 不能一个一个与词典里的比// 因为词典用哈希表存储 直接搜索是 O（1）// 如果直接与词典里一个一个比 时间复杂度会增加很多
                        if(mychar==c) continue;
                        cur[i] = c;
                        if(list.count(cur)!=0 && visit.count(cur) ==0){
                            q.push(cur);             // 将这个点保存在队列里下次通过它找下一个
                            list.erase(cur);      // 将已经访问过的单词词典里面删除 会降低时间复杂度
                            if(cur==endWord){   // 找到结束的单词 退出
                                return res;
                            }
                        }
                        cur[i] = mychar;
                    }
                }
            }
            cout << endl;
        }
        return 0;
    }
};
#endif

// 这是20ms范例 用到了双向BFS 我的只是单向BFS
#if 0
class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> stset,edset,hashset(wordList.begin(),wordList.end());
        stset.insert(beginWord);
        edset.insert(endWord);
        if(!hashset.count(endWord)) return 0;
        int step = 0;
        while(!stset.empty()&&!edset.empty()){
            unordered_set<string> tmp;
            if(stset.size() > edset.size())
                std::swap(stset,edset);
            for(auto w: stset){
                for(int i = 0;i<beginWord.size();i++){
                    string word = w;
                    for(int c = 'a';c<='z';c++){
                        if(c == word[i])
                            continue;
                        else
                            word[i] = c;
                        //cout<<word<<endl;
                        if(edset.count(word)){
                            //cout<<step<<":"<<w<<" "<<word<<endl;
                            return step+2;
                        }
                        if(hashset.count(word)){
                            //cout<<step<<":"<<w<<" "<<word<<endl;
                            tmp.insert(word);
                            hashset.erase(word);
                        }

                    }
                }
            }
            swap(tmp,stset);
            step++;
        }
        return 0;
    }
};
auto _ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
#endif