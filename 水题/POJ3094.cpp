//
// Created by crayonc on 19-1-26.
//

#include <iostream>
#include <string>
using namespace std;
void POJ3094(){
    string s;
    int sum=0;
    while(getline(cin, s)){
        if(s=="#") break;
        for(int i=0;i<s.length();++i){
           if(s[i]==' ') continue;
           sum += (s[i] - 'A' + 1) * (i+1);
        }
        cout << sum << endl;
        sum = 0;
    }
    return;
}