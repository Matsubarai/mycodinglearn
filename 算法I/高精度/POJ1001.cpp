//
// Created by crayonc on 19-2-7.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
string BigIntegerMulit(string &a, string &b);
void POJ1001(){
    string r;
    int n;
    while(cin >> r >> n){
        unsigned long doti = r.find('.');
        if(doti != string::npos){
            r.erase(doti, 1);
        }
        string ans(r);
        for(int i = 1; i < n; ++i){
            ans = BigIntegerMulit(ans, r);
        }

        if(doti != string::npos){
            ans.insert(ans.length() - n * (r.length() - doti), ".");
            while(*(ans.end() - 1) == '0'){
                ans.erase(ans.length() - 1, 1);
            }
            if(*(ans.end() - 1) == '.'){
                ans.erase(ans.length() - 1, 1);
            }
            while(ans[0] == '0'){
                ans.erase(0, 1);
            }
            if(ans.empty()){
                ans.push_back('0'); //极端数据 000.00 1
            }
        }
        else{
            while(ans[0] == '0'){
                ans.erase(0, 1); //极端数据 000010 1
            }
            if(ans.empty()){
                ans.push_back('0'); //极端数据 000000 1
            }
        }
        cout << ans << endl;
    }
    return;
}