//
// Created by crayonc on 19-1-26.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cmpPOJ1083(int a,int b){
    return a>b;
}

void POJ1083(){
    int T,N,s,t;
    int room[201]={0}; //空间优化 降房间数为过道数
    cin >> T;
    for(int i=0;i<T;++i){
        cin >> N;
        for(int j=0;j<N;++j){
            cin >> s >> t;
            if(s>t){
                swap(s,t);
            }
            if(s%2==1){
                ++s;
            }
            if(t%2==1){
                ++t;
            }
            s/=2;t/=2;
            for(int k=s;k<=t;++k){
                ++room[k];   //每个过道的冲突次数 不能使用总冲突次数
            }
        }
        sort(room, room+201, cmpPOJ1083);
        cout << room[0]*10 << endl;
        memset(room, 0, sizeof(room));
    }
    return;
}