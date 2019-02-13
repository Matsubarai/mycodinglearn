//
// Created by crayonc on 19-1-28.
//
/*
 * 二维问题转化为一维, 求海岛有效面积在x轴上的投影区间交
 */
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
struct intervalPOJ1328{ // 区间
    double imin;
    double imax;
    bool operator < (const intervalPOJ1328 &x) const
    { //船新sortcmp方法 重载运算符
        if(imax!=x.imax) return imax<x.imax;
        return imin<x.imin;
    }
}radar[1000];
/*
bool cmpPOJ1328(intervalPOJ1328 a, intervalPOJ1328 b){
    return a.imin<b.imin;
}
*/

void POJ1328(){

    int n, d;

    int island[2];
    //int count = 0; //count为algorithm中容器
    int caseCount = 0;
    int radarCount;
    bool flag;
    double maxBoundary; //类型!!!!
    while (cin >> n >> d){

        if(!n&&!d){
            break;
        }

        for (int i = 0; i < n; ++i) {
            cin >> island[0] >> island[1];
            if(island[1]>d){ //d<=0条件题目未限定
                flag = 1;
                continue;
            }

            else{
                radar[i].imin=island[0] - sqrt(1.0 * d * d - 1.0 * island[1] * island[1]);
                radar[i].imax=island[0] + sqrt(1.0 * d * d - 1.0 * island[1] * island[1]);
            }
        }
        if(flag){
            flag = 0;
            cout << "Case "<<++caseCount<<": -1\n";
            continue;
        }
        sort(radar,radar+n);
        radarCount=1;
        maxBoundary=radar[0].imax;
        for(int i = 1; i < n; ++i){
            if(radar[i].imin > maxBoundary){ //互斥(右侧)
                ++radarCount;
                maxBoundary = radar[i].imax;
            }
            //交 or 包含时
            //交即右交界不变
            //包含即右交界不变 因当前右界与上一右界相等
            /*
            else if(radar[i].imax < maxBoundary){ //包含
                maxBoundary = radar[i].imax;
            }
            else; //交
             */
        }
        cout << "Case " << ++caseCount << ": " << radarCount << endl;
    }
    return;
}