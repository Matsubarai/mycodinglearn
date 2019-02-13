//
// Created by crayonc on 19-1-31.
//
/*
 * dfs+回溯tle
 * 构造公式
 * 记录主对角 次对角(2n-1) 列的占用状态 位运算深搜 tle
 * 行:0-(n-1)
 * 列:0-(n-1)
 * 主对角:n-1-(row-column)
 * 次对角:row+column
 */
#include <iostream>
//#include <vector>

using namespace std;

/*
long long column=0;
long long majorDiagonal=0;
long long minorDiagonal=0;
vector<long long> chess;

void bitdfs(int d, int n){
    int valid = ((1<<n) - 1) & ~(column | (minorDiagonal >> d) | (majorDiagonal >> n - 1 - d)); //有效位置
    while(valid){
        int eumnbit = valid & -valid;
        valid ^= eumnbit; //枚举最右位
        if(d == n - 1){
            chess.push_back(eumnbit);
            for(vector<long long>::iterator it=chess.begin(); it!=chess.end(); it++){
                long long t = *it;
                for(int i = 0; ; ++i){
                    if(t==1){
                        cout << i + 1 << " ";
                        break;
                    }
                    else{
                        t = t >> 1;
                    }
                }
            }
            cout << endl;
            chess.pop_back();
            return;
        }
        else{
            column ^= eumnbit;
            majorDiagonal ^= eumnbit << n - 1 -d;
            minorDiagonal ^= eumnbit << d;
            chess.push_back(eumnbit);
            bitdfs(d + 1, n);
            chess.pop_back();
            column ^= eumnbit;
            majorDiagonal ^= eumnbit << n - 1 -d;
            minorDiagonal ^= eumnbit << d;
        }
    }
}
 */
/*
int chess[301];
void dfs(int d, int n){
    bool flag=false;
    if(d > n){
        for(int i=1; i<=n; ++i){
            cout << chess[i] << " ";
        }
        cout << endl;
        return;
    }
    else{
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j < d; ++j){
                if(chess[j]==i||j-chess[j]==d-i||j+chess[j]==d+i){
                    flag=true;
                    break;
                }
            }
            if(flag){
                flag = false;
                continue;
            }
            else{
                chess[d]=i;
                dfsPOJ3239(d+1,n);
                chess[d]=0;
            }
        }
    }
}
 */
void POJ3239(){
    int n;
    int q[301];
    bool flag=false;
    while(cin >> n){
        if(n==0){
            break;
        }
        //bitdfs(0, n);
        //dfs(1, n);

        else{
            if(n%2==1){
                --n;
                flag = true;
            }
            if(n%3!=0){
                for(int i = 1; i <= n/2; ++i){
                    q[1+((2*(i-1)+n/2-1)%n)] = i;
                    q[n-((2*(i-1)+n/2-1)%n)] = n+1-i;
                }
                if(flag){
                    q[n+1] = n + 1;
                }
                for(int i = 1; i < n; ++i){
                    cout << q[i] << " ";
                }
                if(flag){
                    cout << q[n] << " " << q[n+1] << endl;
                    flag = false;
                }
                else cout << q[n] << endl;
            }
            else if(n%3!=1){
                for(int i = 1; i <= n/2; ++i){
                    q[2*i] = i;
                    q[n+1-2*i] = n+1-i;
                }
                if(flag){
                    q[n+1] = n + 1;
                }
                for(int i = 1; i < n; ++i){
                    cout << q[i] << " ";
                }
                if(flag){
                    cout << q[n] << " " << q[n+1] << endl;
                    flag = false;
                }
                else cout << q[n] << endl;
            }
        }
    }
    return;
}