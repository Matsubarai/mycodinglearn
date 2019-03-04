//
// Created by 93935 on 2019/2/19.
//
/*
 * 枚举等级范围: 对长度为M, 且作为图终点的酋长的等级落在其中的区间进行枚举.对每个符合区间条件图寻最短路.
 */


#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
struct itemPOJ1062{
    int t, v;
    itemPOJ1062(int _t, int _v){
        t = _t;
        v = _v;
    }
};
struct itemsPOJ1062{
    int p, l;
    vector<itemPOJ1062> e;
}gPOJ1062[110];

bool visitPOJ1062[110];
int coinPOJ1062[110];
int mincoinPOJ1062 = INT_MAX;

struct nodePOJ1062{ //小根堆节点
    int u, dis;
    bool operator < (const nodePOJ1062 & t) const{
        return dis > t.dis;
    }
    nodePOJ1062(int _u, int _dis){
        u = _u;
        dis = _dis;
    }
};
void POJ1062(){
    int n, m;
    cin >> m >> n;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> gPOJ1062[i].p >> gPOJ1062[i].l >> x;
        gPOJ1062[0].e.push_back(itemPOJ1062(i, gPOJ1062[i].p)); //设源点为0, 可以由此点原价到达所有物品节点
        for(int j = 0; j < x; ++j){
            int t, v;
            cin >> t >> v;
            gPOJ1062[t].e.push_back(itemPOJ1062(i, v));
        }
    }

    int maxl = gPOJ1062[1].l; //等级中心: 酋长
    for(int i = 0; i <= m; ++i){

        for(int j = 1; j <= n; ++j){
            coinPOJ1062[j] = INT_MAX;
        }
        coinPOJ1062[0] = 0;

        for(int j = 1; j <= n; ++j){
            int lv = gPOJ1062[j].l;
            if(maxl - m + i <= lv && lv <= maxl + i){
                visitPOJ1062[j] = false;
            }
            else{
                visitPOJ1062[j] = true;
            }
        }
        visitPOJ1062[0] = false; //关键初始化
        priority_queue<nodePOJ1062> pq;
        pq.push(nodePOJ1062(0, 0));

        //dijkstra+HeapNode
        while(!pq.empty()){
            int u = pq.top().u;
            pq.pop();
            if(visitPOJ1062[u]) continue;
            visitPOJ1062[u] = true;
            int sz = gPOJ1062[u].e.size();
            for(int j = 0; j < sz; j++){
                int t = (gPOJ1062[u].e)[j].t;
                int v = (gPOJ1062[u].e)[j].v;
                if(!visitPOJ1062[t] && coinPOJ1062[t] > coinPOJ1062[u] + v){
                    coinPOJ1062[t] = coinPOJ1062[u] + v;
                    pq.push(nodePOJ1062(t, coinPOJ1062[t]));
                }
            }
        }

        if(coinPOJ1062[1] < mincoinPOJ1062){
            mincoinPOJ1062 = coinPOJ1062[1];
        }
    }
    cout << mincoinPOJ1062;
    return;
}

