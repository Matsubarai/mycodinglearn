//
// Created by crayonc on 19-1-27.
//
/*
 * 听说可以高斯消元写?
 */

#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
typedef pair<int, int> pr;
int handlePOJ2965=0;
int stepPOJ2965=1<<30;
int moveTo[65536];
int switchPOJ2965[16]={0x111F,0x222F,0x444F,0x888F,
                       0x11F1,0x22F2,0x44F4,0x88F8,
                       0x1F11,0x2F22,0x4F44,0x8F88,
                       0xF111,0xF222,0xF444,0xF888}; //打表 (掩码/mask)
//BFS方法
void bfsPOJ2965(){
    queue<pr> q;
    bool visit[65536] = {0};
    moveTo[handlePOJ2965] = 0;
    visit[handlePOJ2965] = 1;
    q.push(make_pair(handlePOJ2965, 0));
    while(!q.empty()) {
        pr p = q.front();
        q.pop();
        if(p.first==0){
            stepPOJ2965=p.second;
            return;
        }
        for(int i=0;i<16;i++){
            int t = p.first ^ switchPOJ2965[i];

            if(!visit[t]){
                visit[t]=1;
                moveTo[t]=switchPOJ2965[i]; //链表思想
                q.push(make_pair(t, p.second+1));
            }
        }
    }
}

void POJ2965(){
    char t;
    for(int i=0;i<16;++i){
        cin >> t;
        if (t == '+') {
            handlePOJ2965 = handlePOJ2965 | (0x1<<i);
        }
    }
    bfsPOJ2965();
    if(stepPOJ2965==1<<30){
        cout<<"Impossible\n";
    }
    else{
        cout<<stepPOJ2965<<"\n";
        stack<int> s;
        for(int i = 0; moveTo[i] != 0; i ^= moveTo[i]){ //根据mask递推到初态
            for(int k = 0; k < 16; k++){
                if(moveTo[i] == switchPOJ2965[k]){
                    s.push(k);
                    continue;
                }
            }
        }
        while(!s.empty()){
            int cur = s.top();
            s.pop();
            int x = cur / 4 + 1;
            int y = cur % 4 + 1;
            cout << x << " " << y << "\n";
        }
    }
    return;
}
