#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
/*
    The frog distance (humans also call it minimax distance) between two stones
    therefore is defined as the minimum necessary jump range over all possible paths
    between the two stones.
    最低的跳跃范围要求, 指的是两点间所有路径中最长的一步.
*/
using namespace std;
struct pointPOJ2253{
    int x, y;
};

void POJ2253(){
    int n, x, y;
    int cnt = 0;
    while(cin >> n){
        vector<pointPOJ2253> g;
        double dis[n][n];
        if(!n){
            break;
        }
        for(int i = 0; i < n; ++i){
            cin >> x >> y;
            g.push_back((pointPOJ2253){x, y});
        }
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                double deltax = g[j].x - g[i].x;
                double deltay = g[j].y - g[i].y;
                double dist = sqrt(deltax * deltax + deltay * deltay);
                dis[i][j] = dis[j][i] = dist;
            }
        }
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = i + 1; j < n; ++j){
                    if(dis[i][k] < dis[i][j] && dis[k][j] < dis[i][j]){
                        if(dis[i][k] < dis[k][j]){
                            dis[i][j] = dis[j][i] = dis[k][j];
                        }
                        else{
                            dis[i][j] = dis[j][i] = dis[i][k];
                        }
                    }
                }
            }
        }
        cout << "Scenario #" << ++cnt << endl;
        cout << fixed << setprecision(3) << "Frog Distance = " << dis[0][1] << endl;
        cout << endl;
    }
    return;
}
