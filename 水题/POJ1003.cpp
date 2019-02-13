//
// Created by crayonc on 19-1-25.
//
/*
 * 调和级数
 * 0-5.2范围较小 不使用近似公式
 */
#include <iostream>
using namespace std;
void POJ1003(){
    double l, sum = 0.0;
    while(cin >> l){
        if(l < 0.01 || l > 5.20){ //忽略越界情况
            continue;
        }
        for(int i = 2; ; i++){
            sum += 1.0 / i;
            if(sum >= l){
                cout << i - 1 << " card(s)" << endl;
                break;
            }
        }
        sum = 0.0;
    }
    return;
}