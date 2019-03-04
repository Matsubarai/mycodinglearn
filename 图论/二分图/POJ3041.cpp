#include <iostream>
#include <vector>
#include <cstring>
/*
    这是一个最小点覆盖问题
    假设行坐标, 列坐标为顶点, 小行星为链接行列坐标的边
    有一个清除单行/单列的武器
    即求选择最少的行列数即顶点数, 清除所有陨石即所有边.
    此即最小点覆盖
    最小点覆盖 = 最大匹配数.
*/
using namespace std;

vector<int> gPOJ3041[510];

int matchPOJ3041[510]; //matching[列] = 行

bool visitPOJ3041[510]; //列visit

bool roadPOJ3041(int u){
    int sz = gPOJ3041[u].size();
    for(int i = 0; i < sz; ++i){
        int v = gPOJ3041[u][i];
        if(!visitPOJ3041[v]){
            visitPOJ3041[v] = true;
            if(matchPOJ3041[v] == 0 || roadPOJ3041(matchPOJ3041[v])){
                //matching[v] = u;
                matchPOJ3041[v] = u;
                return true;
            }
        }
    }
    return false;
}

void POJ3041(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; ++i){
        int r, c;
        cin >> r >> c;
        gPOJ3041[r].push_back(c);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        memset(visitPOJ3041, 0, sizeof(visitPOJ3041));
        if(roadPOJ3041(i)){
            ++ans;
        }
    }
    cout << ans;
    return;
}