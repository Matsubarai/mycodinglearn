//
// Created by crayonc on 19-1-25.
//
/*
 * (n+d)%23=p, %28=e, %33=i
 * 中国剩余定理
 * 同余定理
 * 21252=23*28*33
 */
#include <iostream>
using namespace std;
void POJ1006(){
    int p, e, i, d;
    int n;
    int count = 0;
    while(cin >> p >> e >> i >> d){
        if(p == -1 && e == -1 && i == -1 && d == -1){ //p=e=i=d=-1时跳出
            break;
        }
        ++count;
        n = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252; //+21252不改变结果 避免得负
        if(n==0){
            n += 21252;
        }
        cout << "Case " << count <<": the next triple peak occurs in "<< n <<" days." << endl;
    }
    return;
}
