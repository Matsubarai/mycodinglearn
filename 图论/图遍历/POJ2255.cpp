//
// Created by crayonc on 19-2-13.
//
/*
 * 知二叉树前序, 中序遍历序列, 求后序遍历序列.
 * 前序遍历序列第一个节点一定是根节点
 * 中序遍历序列根节点两侧是左右子树
 * 前序遍历序列 根节点索引 + 1 是左节点, 左节点索引 + 左子树节点个数(i(根索引) - left(左子树边界))为右节点
 * 数据规模小, 递归运行.
 */
#include <iostream>
#include <string>
//#include <map>
//#include <vector>

using namespace std;
string prePOJ2255, inPOJ2255;
/*
struct nodePOJ2255{
    char l;
    char r;
    nodePOJ2255(int _l, int _r){
        l = _l;
        r = _r;
    }
};
 */
//map<char, vector<nodePOJ2255> > son;
void findPOJ2255(int root, int l, int r){
    if(l > r){
        return;
    }
    int i = l;
    while(i <= r && prePOJ2255[root] != inPOJ2255[i]){
        ++i;
    }
    //son[pre[root]].push_back(nodePOJ2255(pre[root + 1], pre[root + i - l + 1]));

    //以下为后序遍历
    findPOJ2255(root + 1, l, i - 1); //左
    findPOJ2255(root + 1 + i - l, i + 1, r); //右
    cout << prePOJ2255[root]; //根 //push_back即WA
}

void POJ2255(){
    while(cin >> prePOJ2255 >> inPOJ2255){
        findPOJ2255(0, 0, prePOJ2255.size() - 1);
        cout << endl;
    }
    return;
}