//
// Created by crayonc on 19-1-26.
//
/*
 * 凯撒加密, 乱序加密
 * 计数, 排序, 对应相等则原文密文对应
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void POJ2159(){
    string e, r;
    int counte[26]={0}; //代替memset
    int countr[26]={0};
    bool flag=1;
    cin >> e;
    cin >> r;
    /*
    for(char i='A';i<='Z';++i){
        for(int j=0;j<e.length();++j){
            if(e[j]==i){
                ++counte[i-'A'];
            }
            if(r[j]==i){
                ++countr[i-'A'];
            }
        }
    }
    */
    for(int i=0;i<e.length();++i){ //优化
        ++counte[e[i]-'A'];
        ++countr[r[i]-'A'];
    }
    sort(counte,counte+26);
    sort(countr,countr+26);
    for(int i=0;i<26;i++){
        if(counte[i]==countr[i]){
            continue;
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return;
}
