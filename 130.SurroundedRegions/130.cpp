//
// Created by 许雷 on 2018/11/6.
//

//130.被围绕的区域
// 本题采用并查集来做 也可以用BFS DFS来做
class Solution {
public:

    vector<int> unionset;
    vector<bool> isedge;

    void solve(vector<vector<char>>& board) {

        if(board.size()==0 || board[0].size()==0)
            return;

        int m = board.size();
        int n = board[0].size();
        int total = m*n;  // 总格子数

        unionset = vector<int>(total,0);
        isedge = vector<bool>(total, false);

        for(int i = 0;i<total;++i){
            unionset[i] = i;
            // 第i个格子二维坐标
            int x = i/n;
            int y = i%n;

            if(board[x][y]=='O' && (x==0 || x==m-1 || y==0 || y==n-1)){  //边界上的O全部有效
                isedge[i] = true;
            }
        }

        for(int i = 0;i<total;++i){
            int x = i/n;
            int y = i%n;
            int down = x+1;
            int right = y+1;

            if(down<m && board[x][y]==board[down][y]) {
                unionS(i, i + n);
            }
            if(right<n && board[x][y]==board[x][right]){
                unionS(i,i+1);
            }
        }

        for(int i = 0;i<total;++i){
            int x = i/n;
            int y = i%n;
            if(!isedge[find(i)] && board[x][y]=='O') // 如果这个点 没有与边界的O相连 且他是O 就把他变为X
                board[x][y] = 'X';
        }
    }

    void unionS(int m,int n){

        int rootM = find(m);
        int rootN = find(n);

        if(rootM==rootN) // 这两个结点在一起
            return;

        // 把后一个送到前一个上
        unionset[rootN] = rootM;// 合并到此为止

        // 下面是为本题特写的
        if(isedge[rootN])
            isedge[rootM] = true;
    }
    // 找到i的根结点
    // 并把这个路径上的各个节点的父节点都压缩变成他们的祖父节点
    int find(int i){

        while (i!=unionset[i]){
            unionset[i] = unionset[unionset[i]];
            i = unionset[i];
        }
        return i;
    }
};