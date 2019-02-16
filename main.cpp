#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
/*
struct edge{
    int v, w, next;
};
edge e[1000];
int cnt;
int last[1000];

inline void addEdge(int u, int v, int w){
    cnt++;
    e[cnt].w=w;
    e[cnt].v=v;
    e[cnt].next=last[u];
    last[u]=cnt;
}
 */
struct edge{
    int v, w;
    edge(int _v,int _w) {
        v=_v,w=_w;
    }
};
vector<edge> e[1000];
inline void addEdge(int u, int v, int w){
    e[u].push_back(edge(u, v));
}

inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    while(ch < '0'||ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void write(int x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x>9){
        write(x / 10);
    }
    putchar(x % 10 + '0');
}
string BigIntegerMulit(string &a, string &b){ //string作参数必须使用引用类型

    int lena = a.length();
    int lenb = b.length();
    int anst[lena + lenb];
    memset(anst, 0, sizeof(anst));
    for(int ib = 0; ib < lenb; ++ib){
        for(int ia = 0; ia < lena; ++ia){
            anst[ia + ib + 1] += (b[ib] - '0') * (a[ia] - '0');
        }
    }
    for(int i = lena + lenb - 1; i > 0; --i){
        if(anst[i] >= 10){
            anst[i - 1] += anst[i] / 10;
            anst[i] %= 10;
        }
    }
    string ans = "";
    for(int i = 0; i < lena + lenb; ++i){
        ans.push_back(anst[i] + '0');
    }
    if(anst[0] == '0'){
        ans.erase(0, 1);
    }
    return ans;
}

void POJ2255();

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    POJ2255();
    return 0;
}