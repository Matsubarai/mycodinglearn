//
// Created by crayonc on 19-1-29.
//
/*
 * 有些像lisp 运算符前置
 * 将五个bool未知量压缩到int5位中
 * 倒序遍历串展开运算
 * 构造运算律
 * 总共2^5=32种组合
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int mask[5]={0x01,0x02,0x04,0x08,0x10};

void POJ3295(){
    string wff;
    bool t;
    while(cin >> wff){
        if(wff=="0"){
            break;
        }
        stack<bool> s;
        bool flag = true;
        for(int i = 0; i <= 0x1F; ++i){
            for(int j = wff.length() - 1; j >= 0; --j){
                char ch = wff[j];
                if(ch=='p') {
                    t = (i & mask[0]) ? 1 : 0;
                    s.push(t);
                }
                else if(ch=='q') {
                    t = (i & mask[1]) ? 1 : 0;
                    s.push(t);
                }
                else if(ch=='r') {
                    t = (i & mask[2]) ? 1 : 0;
                    s.push(t);
                }
                else if(ch=='s') {
                    t = (i & mask[3]) ? 1 : 0;
                    s.push(t);
                }
                else if(ch=='t') {
                    t = (i & mask[4]) ? 1 : 0;
                    s.push(t);
                }
                else{
                    if(ch=='N'){
                        bool tt=s.top();
                        s.pop();
                        s.push(!tt);
                    }
                    else{
                        bool tt1=s.top();
                        s.pop();
                        bool tt2=s.top();
                        s.pop();
                        //不用位运算符 用逻辑运算符
                        if(ch=='K'){
                            s.push(tt1&&tt2);
                        }
                        if(ch=='A'){
                            s.push(tt1||tt2);
                        }
                        if(ch=='C'){
                            s.push((!tt1)||tt2);
                        }
                        if(ch=='E'){
                            s.push(tt1==tt2);
                        }
                    }
                }
            }
            if(s.top()==false){
                flag = 0;
                break;
            }
            s.pop();
        }
        cout << (flag ? "tautology" : "not") << endl;
    }
    return;
}