//
// Created by crayonc on 19-1-26.
//
/*
 * 枚举棋子选择的组合
 * 一个棋子只能翻转一次(翻转两次<==>翻转零次)
 * 二项系数和次数=2^16
 * 树 BFS/DFS 剪枝
 * 二进制位压缩棋盘状态
 * 异或:指定位做翻转
 */
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pr;
//bool chessPOJ1753[16]={0};
int chessPOJ1753=0;
int stepPOJ1753=1<<30;
/*
bool judge(){
    int tt=chessPOJ1753[0];
    bool flag=1;
    for(int i=1;i<16;++i){
        if(tt!=chessPOJ1753[i]){
            flag=0;
            break;
        }
    }
    return flag;
}
*/
int flipPOJ1753(int choice, int chess){
    if(choice<=11) {
        //chessPOJ1753[choice+4] = !chessPOJ1753[choice+4];
        chess = chess ^ (0x1<<(choice+4));
    }
    if(choice>=4) {
        //chessPOJ1753[choice-4] = !chessPOJ1753[choice-4];
        chess = chess ^ (0x1<<(choice-4));
    }
    if(choice%4!=0) {
        //chessPOJ1753[choice-1] = !chessPOJ1753[choice-1];
        chess = chess ^ (0x1<<(choice-1));
    }
    if((choice+1)%4!=0) {
        //chessPOJ1753[choice+1] = !chessPOJ1753[choice+1];
        chess = chess ^ (0x1<<(choice+1));
    }
    //chessPOJ1753[choice] = !chessPOJ1753[choice];
    chess = chess ^ (0x1<<choice);
    return chess;
}
//DFS方法
void dfsPOJ1753(int choice, int depth){ //DFS 取出n个元素的全部组合的算法
    //if(judge()){
    if(chessPOJ1753==0||chessPOJ1753==65535){
        stepPOJ1753=min(stepPOJ1753, depth - 1);
        return; //求得结果则剪枝
    }
    if(choice>15){
        return; //足够深则回溯
    }
    dfsPOJ1753(choice+1,depth); //展开下一兄弟树
    chessPOJ1753 = flipPOJ1753(choice, chessPOJ1753); //操作
    dfsPOJ1753(choice+1,depth+1); //DFS:搜最近子树
    chessPOJ1753 = flipPOJ1753(choice, chessPOJ1753); //还原
}
//BFS方法
void bfsPOJ1753(){
    queue<pr> q;
    bool visit[65536] = {0};
    q.push(make_pair(chessPOJ1753, 0)); //chess-step对 入队
    while(!q.empty()) {
        pr p = q.front();
        q.pop();
        if(p.first==0||p.first==65535){
            stepPOJ1753=p.second;
            return;
        }
        for(int i=0;i<16;i++){  //BFS:搜所有兄弟树
            int t = flipPOJ1753(i, p.first);
            if(!visit[t]){ //剪枝:已搜到的节点深度<=现搜到的节点, 忽略
                visit[t]=1;
                q.push(make_pair(t, p.second+1));
            }
        }
    }
}

void POJ1753(){
    char t;
    for(int i=0;i<16;++i){
        cin >> t;
        if (t == 'b') {
            //chessPOJ1753[i]=1;
            chessPOJ1753 = chessPOJ1753 | (0x1<<i);
        }
    }
    //dfsPOJ1753(0, 1);
    bfsPOJ1753();
    if(stepPOJ1753==1<<30){
        cout<<"Impossible\n";
    }
    else{
        cout<<stepPOJ1753<<"\n";
    }
    return;
}