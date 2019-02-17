//
// Created by crayonc on 19-2-17.
//
#include <iostream>
//#include <vector>
#include <algorithm>

using namespace std;
struct edgePOJ1789{
    int u, v, w;
    edgePOJ1789(){}
    /*
    friend bool operator <(const edgePOJ1789 & t1, const edgePOJ1789 & t2){
        return t1.w < t2.w;
    }
     */
    /*
    bool operator <(const edgePOJ1789 & t) const{
        return w < t.w;
    }
     */
};

bool cmp(edgePOJ1789 a, edgePOJ1789 b){
    return a.w < b.w;
}

//全局变量AC.

int familyPOJ1789[2005];
struct edgePOJ1789 g[2005*2004/2];
char truck[2005][10];

int findPOJ1789(int u){
    if(familyPOJ1789[u] == u) {
        return u;
    }
    else {
        familyPOJ1789[u] = findPOJ1789(familyPOJ1789[u]);
        return familyPOJ1789[u];
    }
}

void POJ1789(){
    int n;
    while(cin >> n) {
        if(!n){
            return;
        }
        for (int i = 0; i < n; ++i) {
            cin >> truck[i];
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int t = 0;
                for(int k = 0; k < 7; ++k){
                    if(truck[i][k] != truck[j][k]){
                        ++t;
                    }
                }
                g[cnt].u = i;
                g[cnt].v = j;
                g[cnt++].w = t;
            }
        }

        sort(g, g + cnt, cmp);

        for(int i = 0; i < n; ++i){
            familyPOJ1789[i] = i;
        }

        int tot = 0;
        int k = 0;
        for(int i = 0; i < cnt; ++i){
            int u = findPOJ1789(g[i].u);
            int v = findPOJ1789(g[i].v);
            if(u != v){
                familyPOJ1789[u] = v;
                tot += g[i].w;
                ++k;
                if(k == n - 1){
                    break;
                }
            }
        }

        cout << "The highest possible quality is 1/" << tot << "." << endl;
    }
    return;
}

