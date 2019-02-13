//
// Created by crayonc on 19-1-25.
//
#include <iostream>
using namespace std;
void POJ1004(){
    double sum=0.0, t;
    for(int i=0; i<12; i++){
        cin >> t;
        sum += t;
    }
    cout << "$" << sum/12.0;
    return;
}

