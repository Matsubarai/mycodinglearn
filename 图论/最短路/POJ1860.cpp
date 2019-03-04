//
// Created by crayonc on 19-2-17.
//
/*
 * 资本增长:
 * 存在一个正权环, 使得在走完此环时, 同样的节点(货币)资本增长.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
struct edgePOJ1860{
    int v;
    double r, c;
    edgePOJ1860(int _v, double _r, double _c){
        v = _v, r = _r, c = _c;
    }
};
void POJ1860(){
    int n, m, s;
    double v;
    cin >> n >> m >> s >> v;
    vector<edgePOJ1860> g[n + 1];
    int a, b;
    double rab, cab, rba, cba;
    for(register int i = 0; i < m; ++i){
        cin >> a >> b >> rab >> cab >> rba >> cba;
        //g[a].emplace_back(b, rab, cab);
        //g[b].emplace_back(a, rba, cba);
        g[a].push_back(edgePOJ1860(b, rab, cab));
        g[b].push_back(edgePOJ1860(a, rba, cba));
    }
    double dis[n + 1];
    bool visit[n + 1];
    int in[n + 1];
    memset(dis, 0, sizeof(dis));
    memset(visit, 0, sizeof(visit));
    memset(in, 0, sizeof(in));
    dis[s] = v;
    queue<int> q;
    q.push(s);
    visit[s] = true;
    while(!q.empty()){
        int cnt = q.front();
        visit[cnt] = false;
        q.pop();
        int sz = g[cnt].size();
        for(register int i = 0; i < sz; ++i){
            struct edgePOJ1860 cntEdge = g[cnt][i];
            int cntv = cntEdge.v;
            double cntw = (dis[cnt] - cntEdge.c) * cntEdge.r;
            if(dis[cntv] < cntw){
                dis[cntv] = cntw;
                ++in[cntv];
                if(in[cntv] == n){ //松弛操作达到n次则说明有正环
                    cout << "YES";
                    return;
                }
                if(!visit[cntv]){
                    q.push(cntv);
                    visit[cntv] = true;
                }
            }
        }
    }
    cout << "NO";
    return;
}