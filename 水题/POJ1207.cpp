//
// Created by crayonc on 19-1-25.
//
#include <iostream>
using namespace std;
void POJ1207(){
    bool flag=0;
    int i, j, count = 1, maxcount,tt;
    maxcount=-(1<<30);
    while(cin >> i >> j){
        if(i>j){//i, j关系不定
            swap(i,j);
            flag=1;
        }
        for(int t = i;t<=j;t++){
            tt=t;
            while(tt!=1){
                if(tt%2==0){
                    tt /= 2;
                }
                else{
                    tt =3*tt+1;
                }
                ++count;
            }
            if(count > maxcount){
                maxcount=count;
            }
            count=1;
        }
        if(flag){//原样输出
            swap(i, j);
            flag=0;
        }
        cout << i << " " << j << " " << maxcount << endl;
        maxcount=-(1<<30); //重置
    }
    return;
}