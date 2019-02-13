//
// Created by crayonc on 19-1-25.
//

#include <iostream>
#include <cmath>
//#include <cstdio>
#include <iomanip> //流算子

using namespace std;
void POJ3299(){
    char l;
    double i;
    bool flag=0;
    double t=101, d=101, h=101;
    while(cin >> l >>i){
        if(l=='T'){
            t=i;
        }
        else if(l=='D'){
            d=i;
        }
        else if(l=='H'){
            h=i;
        }
        else if(l=='E'){
            break;
        }
        else;
        if(flag){
            if(t==101){
                t = h - 0.5555 * (6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d + 273.16)))) - 10.0);
            }
            else if(d==101){
                d = (1 / ((1 / 273.16) - (log(((h - t) / 0.555 + 10.0) / 6.11) / 5417.7530))) - 273.16;
            }
            else if(h==101){
                h = t + 0.5555 * (6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d+273.16)))) - 10.0);
            }
            else;
            //printf("T %.1f D %.1f H %.1f\n",t,d,h);
            cout<<setprecision(1)<<fixed<<"T "<<t<<" D "<<d<<" H "<<h<<endl; //小数后一位
            flag = 0;
            t=101;
            d=101;
            h=101;
            continue;
        }
        flag=1;
    }
    return;
}