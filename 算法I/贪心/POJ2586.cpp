//
// Created by crayonc on 19-1-29.
//
/*
 * 题意:固定盈利亏损 任意连续五个月都亏损
 * 贪出最大收益
 */
#include <iostream>
using namespace std;
void POJ2586(){
    int s, d, surplus;
    while(cin >> s >> d){
        if(s>=4*d){
            cout << "Deficit\n"; //dddddddddddd
            continue;
        }
        else if(2*s>=3*d)  surplus = 3*s-9*d; //sddddsddddsdd
        else if(3*s>=2*d) surplus = 6*s-6*d;//ssdddssdddss
        else if(4*s>=d) surplus = 8*s-4*d;//sssddsssddss
        else surplus = 10*s-2*d; //ssssdssssdss

        if(surplus<0) cout <<  "Deficit\n";
        else cout << surplus << endl;
    }
    return;
}