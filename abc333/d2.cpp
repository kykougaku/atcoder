#include <bits/stdc++.h>

using namespace std;
//union find
class UnionFind{
    public:
        vector<int> par, siz;
        UnionFind(int n) : par(n, -1), siz(n, 1) {}//コンストラクタ　メンバ初期化子リスト
        int root(int x){
            if(par.at(x) == -1) return x;
            else return par.at(x) = root(par.at(x));
        }
        bool issame(int x, int y){
            return root(x) == root(y);
        }
        bool unite(int x, int y){
            x = root(x);
            y = root(y);
            if(x == y) return false;
            if(siz.at(x) < siz.at(y)) swap(x, y);
            par.at(y) = x;
            siz.at(x) += siz.at(y);
            return true;
        }
        int size(int x){
            return siz.at(root(x));
        }
};

int main (){
    
    return 0;
}