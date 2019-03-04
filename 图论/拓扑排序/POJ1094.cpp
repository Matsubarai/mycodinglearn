//
// Created by crayonc on 19-2-18.
//
/*
 * 关系式排序
 * 唯一排序即排序成立
 * 多种排序则排序不确定
 * 排序中存在无法进入的元素(存在环)则说明排序矛盾
 *
 * 范围: 前n个元素.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
vector<int> ansPOJ1094;
bool uniquePOJ1094;
bool cyclePOJ1094;
int n, m;
void tsortPOJ1094(vector<vector<bool> > & g){
    ansPOJ1094.clear();
    int sz = g.size();
    int degree[sz];
    memset(degree, 0, sizeof(degree));
    for(int i = 0; i < sz; ++i){
        for(int j = 0; j < sz; ++j){
            if(g[i][j]){
                ++degree[j];
            }
        }
    }
    queue<int> q;
    uniquePOJ1094 = true;
    int tot = 0;
    for(int i = 0; i < sz; ++i){
        if(!degree[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        if(q.size() > 1){
            uniquePOJ1094 = false;
        }
        int cnt = q.front();
        ansPOJ1094.push_back(cnt);
        for(int i = 0; i < sz; ++i){
            if(g[cnt][i]){
                --degree[i];
                if(!degree[i]){
                    q.push(i);
                }
            }
        }
        ++tot;
        q.pop();
    }
    if(sz != tot) cyclePOJ1094 = true;
}

void POJ1094(){
    char t1, t2, t;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        cyclePOJ1094 = false;
        vector<vector<bool> > gPOJ1094;
        bool flag = false;
        for(int i = 0; i < m; ++i){
            cin >> t1 >> t >> t2;
            if(flag){
                continue;
            }
            int num1 = t1 - 'A';
            int num2 = t2 - 'A';
            int maxnum = max(num1, num2);
            if(gPOJ1094.size() < maxnum + 1){
                int oldsize = gPOJ1094.size();
                for(int j = 0; j < oldsize; ++j){
                    for(int k = 0; k < maxnum + 1 - oldsize; ++k){
                        gPOJ1094[j].push_back(false);
                    }
                }
                for(int j = 0; j < maxnum + 1 - oldsize; ++j){
                    gPOJ1094.push_back(vector<bool>(maxnum + 1, false));
                }
            }
            gPOJ1094[num1][num2] = true;
            int sz = gPOJ1094.size();
            tsortPOJ1094(gPOJ1094);
            if(cyclePOJ1094){
                cout << "Inconsistency found after " << i + 1 << " relations." << endl;
                flag = true;
                continue;
            }
            if(sz < n){
                if(i == m - 1){
                    cout << "Sorted sequence cannot be determined." << endl;
                    flag = true;
                }
            }
            else{
                if(uniquePOJ1094){
                    cout << "Sorted sequence determined after " << i + 1 << " relations: ";
                    for(int j = 0; j < n; ++j){
                        cout << (char)(ansPOJ1094[j] + 'A');
                    }
                    cout << "." << endl;
                    flag = true;
                }
                else{
                    if(i == m - 1){
                        cout << "Sorted sequence cannot be determined.\n";
                        flag = true;
                    }
                }
            }
        }
    }
    return;
}