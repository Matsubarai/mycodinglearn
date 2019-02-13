//
// Created by crayonc on 19-1-25.
//
#include <iostream>
#include <cmath>
using namespace std;
void POJ1005(){
    int n, year, count=1;
    double x, y;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        year = ceil((0.5*(x*x+y*y)*3.1415926)/50); //天花板除ceil 得期望时间的向上整以满足条件
        cout << "Property "<<count<<": This property will begin eroding in year "<<year<<"."<<endl;
        ++count;
    }
    cout << "END OF OUTPUT.";
    return;
}